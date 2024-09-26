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


//Time Limit Exceeded
class Solution {


private:

	void dfs(int index, int sum, int min, int k, vector<int>& nums1, vector<int>& nums2)
	{
		if (0 == k)
		{
			ret = max(ret, static_cast<long long>(sum) * min);
			return;
		}

		for (int i = index; i < nums1.size(); i++)
		{
			int m = std::min(min, nums2[i]);

			dfs(i + 1, nums1[i] + sum, m, k - 1, nums1, nums2);
		}
	}


	long long ret;

public:
	long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {


		dfs(0, 0, INT_MAX, k, nums1, nums2);

		return ret;

	}
};


class Solution {
public:
	long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

		vector<pair<int, int>> p;

		for (int i = 0; i < nums1.size(); i++)
		{
			p.push_back({ nums1[i], nums2[i] });
		}

		sort(p.begin(), p.end(), [](const pair<int, int>& l, const pair<int, int>& r)
			{
				return l.second > r.second;
			}
		);

		long long sum = 0;
		int m = INT_MAX;

		std::priority_queue<int, vector<int>, greater<int>> pq;

		for (int i = 0; i < k; i++)
		{
			sum += p[i].first;
			pq.push(p[i].first);
		}

		long long ret = sum * p[k - 1].second;

		for (int i = k; i < nums1.size(); i++)
		{
			sum -= pq.top();

			pq.pop();

			sum += p[i].first;

			pq.push(p[i].first);

			ret = std::max(ret, sum * p[i].second);

		}

		return ret;
	}
};

class Solution {


	void dfs(int index, int k, int sum, int min, vector<int>& nums1, vector<int>& nums2)
	{
		if (0 == k)
		{
			ret = max(ret, sum * min);
			return;
		}

		if (nums1.size() <= index)
		{
			return;
		}

		for (int i = index; i < nums1.size() - k + 1; i++)
		{
			dfs(i + 1, k - 1, nums1[i] + sum, std::min(nums2[i], min), nums1, nums2);
		}
	}

	int ret = 0;

public:
	long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

		dfs(0, k, 0, INT_MAX, nums1, nums2);

		return ret;
	}
};

class Solution {
public:
	long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k) {

		int n = nums1.size();
		std::vector<std::pair<int, int>> pairs(n);

		// nums1[i]�� nums2[i]�� ������ ����
		for (int i = 0; i < n; ++i) {
			pairs[i] = { nums1[i], nums2[i] };
		}

		// nums2�� �������� �������� ����
		std::sort(pairs.begin(), pairs.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
			return b.second < a.second;
			});

		// �ּ� ���� ����Ͽ� ���� k���� nums1 ���� ����
		std::priority_queue<int, std::vector<int>, std::greater<int>> topKHeap;
		long long topKSum = 0;

		// ó�� k���� ���� topKSum�� ���ϰ�, �ּ� ���� ����
		for (int i = 0; i < k; ++i) {
			topKSum += pairs[i].first;
			topKHeap.push(pairs[i].first);
		}

		// ó�� k���� �����κ��� ����� �ʱ� ����
		long long answer = topKSum * pairs[k - 1].second;

		// ������ ��ҵ鿡 ���� �ݺ��ϸ� ���� ���
		for (int i = k; i < n; ++i) {
			// �ּ� ������ ���� ���� ���� �����ϰ�, ���� ���� ����
			topKSum += pairs[i].first - topKHeap.top();
			topKHeap.pop();
			topKHeap.push(pairs[i].first);

			// ���� ���� ����ϰ�, �ִ� ���� ����
			answer = std::max(answer, topKSum * pairs[i].second);
		}

		return answer;
	}
};