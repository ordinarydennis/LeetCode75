class Solution {
public:
	long long totalCost(vector<int>& costs, int k, int candidates) {

		auto compare = [](pair<int, int>& a, pair<int, int>& b) {

			if (a.first != b.first)
				return a.first > b.first;

			return a.second > b.second;
		};

		priority_queue<
			pair<int, int>, vector<pair<int, int>>, decltype(compare)
		> q;


		for (int i = 0; i < costs.size(); i++)
		{
			q.push({ costs[i], i });
		}

		//for (int i = 0; i < costs.size(); i++)
		//{
		//	cout << q.top().first <<" " << q.top().second << endl;
		//	q.pop();
		//}

		long long ret = 0;

		for (int i = 0; i < k; i++)
		{
			ret += q.top().first;
			q.pop();
		}

		return ret;

	}
};