class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {

		double ret = std::accumulate(nums.begin(), nums.begin() + k, 0);

		double sum = 0.0;

		for (int i = 1; i <= nums.size() - k; i++)
		{
			sum -= nums[i- 1];
			sum += nums[i + k - 1];
			ret = max(ret, sum);
		}

		return ret / k ;
	}
};