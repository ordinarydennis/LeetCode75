class Solution {

	struct TrieNode
	{
		vector<TrieNode*> list;

		bool isEnd = false;

		TrieNode()
			:list('z' - 'a' + 1),
			isEnd(false)
		{

		}

		TrieNode* find(char c)
		{
			return list[c - 'a'];
		}

		void AddChild(char c, TrieNode* node)
		{
			list[c - 'a'] = node;
		}

	};

	struct Trie
	{

		Trie()
			:root(new TrieNode)
		{

		}

		void Add(string& w)
		{
			auto* node = root;

			for (char c : w)
			{
				auto* child = node->find(c);

				if (nullptr == child)
				{
					child = new TrieNode();
					node->AddChild(c, child);
				}

				node = child;
			}
			node->isEnd = true;
		}

		vector<string> find(string s)
		{
			auto* node = root;

			vector<string> outList;

			for (char c : s)
			{
				auto* child = node->find(c);

				if (nullptr == child)
				{
					break;
				}

				string out = string(c, 1);

				findString(child, out, outList);

				node = child;

				if (3 <= outList.size())
				{
					break;
				}
			}

			return outList;

		}

		void findString(TrieNode* node, string& out, vector<string>& outList)
		{
			if (3 <= outList.size())
			{
				return;
			}
			if (node->isEnd)
			{
				outList.push_back(out);
				return;
			}

			for (int i = 0; i < node->list.size(); i++)
			{
				auto* n = node->list[i];

				if (!n)
				{
					continue;
				}

				char c = i + 'a';

				out.push_back(c);

				findString(n, out, outList);

				out.pop_back();
			}
		}



	private:
		TrieNode* root = nullptr;

	};



public:
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {


		sort(products.begin(), products.end());

		Trie* trie = new Trie;


		vector<vector<string>> ret;

		for (auto& p : products)
		{
			trie->Add(p);
		}


		string s;

		for (int i = 0; i < searchWord.size(); i++)
		{
			s += searchWord[i];

			auto strList = trie->find(s);

			ret.push_back(std::move(strList));
		}

		return ret;
	}
};


// Custom class Trie with function to get 3 words starting with given prefix
class Trie
{
	// Node definition of a trie
	struct Node {
		bool isWord = false;
		vector<Node*> children{ vector<Node*>(26, NULL) };
	} *Root, * curr;

	// Runs a DFS on trie starting with given prefix and adds all the words in the result, limiting result size to 3
	void dfsWithPrefix(Node* curr, string& word, vector<string>& result) {
		if (result.size() == 3)
			return;
		if (curr->isWord)
			result.push_back(word);

		// Run DFS on all possible paths.
		for (char c = 'a'; c <= 'z'; c++)
			if (curr->children[c - 'a']) {
				word += c;
				dfsWithPrefix(curr->children[c - 'a'], word, result);
				word.pop_back();
			}
	}

public:
	Trie() {
		Root = new Node();
	}
	// Inserts the string in trie.
	void insert(string& s) {
		// Points curr to the root of trie.
		curr = Root;
		for (char& c : s) {
			if (!curr->children[c - 'a'])
				curr->children[c - 'a'] = new Node();
			curr = curr->children[c - 'a'];
		}
		// Mark this node as a completed word.
		curr->isWord = true;
	}
	vector<string> getWordsStartingWith(string& prefix) {
		curr = Root;
		vector<string> result;

		// Move curr to the end of prefix in its trie representation.
		for (char& c : prefix) {
			if (!curr->children[c - 'a'])
				return result;
			curr = curr->children[c - 'a'];
		}
		dfsWithPrefix(curr, prefix, result);
		return result;
	}
};
class Solution {
public:
	vector<vector<string>> suggestedProducts(vector<string>& products,
		string searchWord) {
		Trie trie = Trie();
		vector<vector<string>> result;

		// Add all words to trie.
		for (string& w : products)
			trie.insert(w);
		string prefix;
		for (char& c : searchWord) {
			prefix += c;
			result.push_back(trie.getWordsStartingWith(prefix));
		}
		return result;
	}
};

//https://leetcode.com/problems/search-suggestions-system/editorial/?envType=study-plan-v2&envId=leetcode-75