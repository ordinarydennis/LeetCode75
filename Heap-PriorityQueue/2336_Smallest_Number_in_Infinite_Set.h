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


class SmallestInfiniteSet {
public:
	SmallestInfiniteSet() {

	}

	int popSmallest() {

		if (q.size())
		{
			if (smallest < q.top())
			{
				return smallest++;
			}
			else
			{
				int n = q.top();
				q.pop();
				st.erase(n);

				if (n == smallest)
				{
					smallest++;
				}
				return n;
			}
		}

		return smallest++;
	}

	void addBack(int num) {

		if (st.count(num))
		{
			return;
		}

		st.insert(num);
		q.push(num);

	}



private:
	priority_queue<int, vector<int>, greater<int>> q;

	set<int> st;


	int smallest = 1;
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

		if (pq.size())
		{
			int n = pq.top();
			pq.pop();
			st.erase(n);
			return n;
		}
		
		return smallest++;
	}

	void addBack(int num) {

		if (smallest <= num)
		{
			return;
		}

		if (st.count(num))
		{
			return;
		}

		st.insert(num);
		pq.push(num);
	}

private:
	std::unordered_set<int> st;
	std::priority_queue<int, vector<int>, greater<int>> pq;

	int smallest = 1;

};
