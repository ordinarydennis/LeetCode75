class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {

		int ret = 0;

		for (int s = 0; s < nums.size(); s++)
		{
			for (int e = s; e < nums.size(); e++)
			{
				int sum = std::accumulate(
					nums.begin() + s,
					nums.begin() + e + 1,
					0
				);

				if (k == sum)
					ret++;
			}
		}

		return ret;
	}
};

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {

		int ret = 0;

		std::unordered_map<int, int> m;

		int sum = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];

			if (k == sum)
				ret++;
			
			if (m.count(sum - k))
				ret += m[sum - k];
			
			m[sum]++;
		}

		return ret;
	}
};