class RecentCounter {
public:
	RecentCounter() {

	}

	int ping(int t) {

		q.push(t);

		while (q.size() && t - 3000 > q.front())
			q.pop();
		
		return q.size();
	}


private:
	std::queue<int> q;

};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

class RecentCounter {
public:
	RecentCounter() {

	}

	int ping(int t) {

		req.push(t);

		while (req.front() < t - 3000)
			req.pop();

		return req.size();
	}


private:
	std::queue<int> req;
};
