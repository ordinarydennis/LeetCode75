class Solution {

	void dfs(int index, int sum, int min, vector<int>& nums1, vector<int>& nums2, vector<bool>& visited, int k)
	{
		if (0 == k)
		{
			ret = std::max(ret, sum * min);
			return;
		}

		int size = nums1.size();

		for (int i = index; i < size; i++)
		{
			if (visited[i])
				continue;

			sum += nums1[index];

			min = std::min(min, nums2[index]);

			visited[index] = true;

			dfs(index + 1, sum, min, nums1, nums2, visited, k - 1);

			sum -= nums1[index];

			visited[index] = false;
		}

	}

	int ret = 0;

public:
	long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

		vector<bool> visited(nums1.size());

		dfs(0, 0, 1, nums1, nums2, visited, k);

		return ret;
	}
}

class Solution {
public:
	long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

		vector<pair<long long, long long>> p;

		for (int i = 0; i < nums1.size(); i++)
		{
			p.emplace_back(pair<int, int>{ nums1[i], nums2[i] });
		}


		sort(p.begin(), p.end(), [](const pair<int, int>& l, const pair<int, int>& r)
			{
				return l.second > r.second;
			}
		);

		priority_queue<int, vector<int>, greater<int>> q;

		long long sum = 0;

		for (int i = 0; i < k; i++)
		{
			q.push(p[i].first);

			sum += p[i].first;
		}

		long long ret = sum * p[k - 1].second;

		for (int i = k; i < nums1.size(); i++)
		{
			sum -= q.top();

			sum += p[i].first;

			q.pop();

			q.push(p[i].first);

			ret = max(ret, sum * p[i].second);
		}

		return ret;
	}
};
