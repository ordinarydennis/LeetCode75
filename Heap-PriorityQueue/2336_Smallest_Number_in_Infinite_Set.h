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

class SmallestInfiniteSet {
public:
	SmallestInfiniteSet() {
	}

	int popSmallest() {

		if (list.size())
		{
			int n = *list.begin();
			list.erase(n);
			return n;
		}

		return nextPop++;

	}

	void addBack(int num) {

		if (nextPop <= num)
			return;

		list.insert(num);
	}

private:
	set<int> list;
	int nextPop = 1;

};


class SmallestInfiniteSet {
public:
	SmallestInfiniteSet() {

	}

	int popSmallest() {

		if (q.size())
		{
			int n = q.top();
			q.pop();
			s.erase(n);
			return n;
		}

		return nextPop++;
	}

	void addBack(int num) {

		if (s.count(num))
			return;

		if (nextPop <= num)
			return;

		q.push(num);
		s.insert(num);
	}


private:
	int nextPop = 1;
	priority_queue<int, vector<int>, greater<int>> q;
	unordered_set<int> s;
};


/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */