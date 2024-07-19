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