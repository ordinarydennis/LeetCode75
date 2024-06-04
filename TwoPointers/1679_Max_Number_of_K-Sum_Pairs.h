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