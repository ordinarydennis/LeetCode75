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

		// nums1[i]와 nums2[i]를 쌍으로 묶음
		for (int i = 0; i < n; ++i) {
			pairs[i] = { nums1[i], nums2[i] };
		}

		// nums2를 기준으로 내림차순 정렬
		std::sort(pairs.begin(), pairs.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
			return b.second < a.second;
			});

		// 최소 힙을 사용하여 상위 k개의 nums1 값을 관리
		std::priority_queue<int, std::vector<int>, std::greater<int>> topKHeap;
		long long topKSum = 0;

		// 처음 k개의 값을 topKSum에 더하고, 최소 힙에 넣음
		for (int i = 0; i < k; ++i) {
			topKSum += pairs[i].first;
			topKHeap.push(pairs[i].first);
		}

		// 처음 k개의 쌍으로부터 계산한 초기 점수
		long long answer = topKSum * pairs[k - 1].second;

		// 나머지 요소들에 대해 반복하며 점수 계산
		for (int i = k; i < n; ++i) {
			// 최소 힙에서 가장 작은 값을 제거하고, 현재 값을 더함
			topKSum += pairs[i].first - topKHeap.top();
			topKHeap.pop();
			topKHeap.push(pairs[i].first);

			// 현재 점수 계산하고, 최대 점수 갱신
			answer = std::max(answer, topKSum * pairs[i].second);
		}

		return answer;
	}
};