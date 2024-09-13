class Trie {

private:
	struct TrieObj
	{
		vector<TrieObj*> trieList;
		bool isWorld = false;

		TrieObj()
			:trieList('z' - 'a' + 1, nullptr),
			isWorld(false)
		{

		}
	};

	void add(TrieObj* root, int index, string& w)
	{
		auto t = new TrieObj();

		root->trieList[w[index] - 'a'] = t;

		if (index == w.size() - 1)
		{
			t->isWorld = true;
			return;
		}

		add(t, index + 1, w);
	}

	bool find(TrieObj* root, int index, string& w)
	{
		if (w.size() == index)
		{
			return false;
		}

		if (nullptr == root->trieList[w[index] - 'a'])
		{
			return false;
		}

		auto* t = root->trieList[w[index] - 'a'];

		if (t->isWorld && w.size() -1 == index)
		{
			return true;
		}
		else
		{
			return find(t, index + 1, w);
		}
	}

	bool findPrefix(TrieObj* root, int index, string& w)
	{
		if (w.size() == index)
		{
			return true;
		}

		if (nullptr == root->trieList[w[index] - 'a'])
		{
			return false;
		}

		auto* t = root->trieList[w[index] - 'a'];

		return findPrefix(t, index + 1, w);
	}


public:
	Trie() {

		root = new TrieObj();

	}

	void insert(string word) {

		add(root, 0, word);

	}

	bool search(string word) {

		return find(root, 0, word);

	}

	bool startsWith(string prefix) {

		return findPrefix(root, 0, prefix);
	}


private:
	TrieObj* root;

};


class Trie {

private:
	struct Node
	{
		vector<Node*> childList;
		bool isEnd = false;

		Node()
			: childList('z' - 'a' + 1, nullptr),
			isEnd(false)
		{

		}

		Node* GetChild(char c)
		{
			return childList[GetCharToIndex(c)];
		}

		void AddChild(char c, Node* child)
		{
			childList[GetCharToIndex(c)] = child;
		}

		void SetEnd() { isEnd = true; };

		bool IsEnd() { return isEnd; };

	private:
		int GetCharToIndex(char c) { return c - 'a'; }

	};



public:
	Trie() {
		root = new Node();
	}

	void insert(string word) {

		Node* node = root;

		for (char c : word)
		{
			auto* childNode = node->GetChild(c);

			if (nullptr == childNode)
			{
				childNode = new Node();
				node->AddChild(c, childNode);
			}

			node = childNode;
		}

		node->SetEnd();
	}

	bool search(string word) {

		auto* node = findNode(word);

		return node && node->IsEnd();
	}

	bool startsWith(string prefix) {

		Node* node = findNode(prefix);

		return (nullptr != node);
	}


private:
	Node* findNode(string prefix) {

		Node* node = root;

		for (char c : prefix)
		{
			auto* childNode = node->GetChild(c);

			if (nullptr == childNode)
			{
				return nullptr;
			}

			node = childNode;
		}

		return node;
	}

private:
	Node* root = nullptr;

};


//Space Complexity O(ALPHABET_SIZE ¡¿ L¡¿ N)
//https://www.quora.com/What-is-the-complexity-of-Trie


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


class Trie {
public:
	Trie() {

		mRoot = new Node();
	}

	void insert(string word) {

		AddNode(mRoot, word, 0);

	}

	bool search(string word) {

		return SearchNode(mRoot, word, 0);

	}

	bool startsWith(string prefix) {

		return SearchNodePrefix(mRoot, prefix, 0);

	}


private:
	
	struct Node
	{
		bool isWord = false;
		std::vector<Node*> child;

		Node()
			:child('z' - 'a' + 1)
		{

		}
	};


	Node* mRoot = nullptr;

	void AddNode(Node* p, string word, int index)
	{
		auto* childNode = p->child[word[index] - 'a'];

		if (!childNode)
		{
			childNode = new Node;
			p->child[word[index] - 'a'] = childNode;
		}
		
		if (word.size() - 1 == index)
		{
			childNode->isWord = true;
			return;
		}

		AddNode(childNode, word, index + 1);
	}


	bool SearchNode(Node* p, string word, int index)
	{
		auto* childNode = p->child[word[index] - 'a'];

		if (nullptr == childNode)
		{
			return false;
		}

		if (word.size() - 1 == index)
		{
			if (childNode->isWord)
			{
				return true;
			}
			else
			{
				return false;
			}
			
		}

		return SearchNode(childNode, word, index + 1);
	}


	bool SearchNodePrefix(Node* p, string word, int index)
	{
		auto* childNode = p->child[word[index] - 'a'];

		if (nullptr == childNode)
		{
			return false;
		}

		if (word.size() - 1 == index)
		{
			return true;
		}

		return SearchNode(childNode, word, index + 1);
	}

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

"apple"