class SmallestInfiniteSet {
public:
	SmallestInfiniteSet() {

		list.clear();

	}

	int popSmallest() {

		if (list.size())
		{
			int n = *list.begin();

			if (n < nextPop)
			{
				list.erase(n);
				return n;
			}
			else if (n == nextPop)
			{
				list.erase(n);
			}
		}

		return nextPop++;

	}

	void addBack(int num) {

		list.insert(num);

	}

private:
	set<int> list;

	int nextPop = 1;

};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */