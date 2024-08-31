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


class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {

		double sum = accumulate(nums.begin(), nums.begin() + k, 0);
		double max = sum / k;

		for (int i = k; i < nums.size(); i++)
		{
			sum += nums[i] - nums[i - k];
			max = std::max(max, sum / k);
		}

		return max;
	}
};