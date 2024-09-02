class Solution {
public:
	int maxOperations(vector<int>& nums, int k) {

		sort(nums.begin(), nums.end());

		int left = 0;
		int right = nums.size() - 1;

		int ret = 0;

		while (left < right)
		{
			int sum = nums[left] + nums[right];

			if (k == nums[left] + nums[right])
			{
				left++;
				right--;
				ret++;
				continue;
			}

			(sum < k) ? left++ : right--;

		}

		return ret;

	}
};


class Solution {
public:
	int maxOperations(vector<int>& nums, int k) {

		sort(nums.begin(), nums.end());

		int left = 0;
		int right = nums.size() - 1;
		int ret = 0;

		while (left < right)
		{
			if (k == nums[left] + nums[right])
			{
				left++;
				right--;
				ret++;
				continue;
			}

			(k < nums[left] + nums[right]) ? right-- : left++;
		}

		return ret;
	}
};


class Solution {
public:
	int maxOperations(vector<int>& nums, int k) {

		unordered_map<int, int> m;

		int count = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (0 < m[k - nums[i]])
			{
				m[k - nums[i]]--;
				count++;
			}
			else
			{
				m[nums[i]]++;
			}
		}

		return count;
	}
};