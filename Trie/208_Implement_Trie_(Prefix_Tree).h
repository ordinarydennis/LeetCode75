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
