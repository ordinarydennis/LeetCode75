class Solution {
public:
	int longestOnes(vector<int>& nums, int k) {

		int left = 0;

		int ret = 0;

		for (int right = 0; right < nums.size(); right++)
		{
			if (0 == nums[right])
				k--;

			if (0 <= k)
				ret = max(ret, right - left + 1);

			if (k < 0)
			{
				while (1 == nums[left])
					left++;

				left++;
				k++;
			}
		}

		return ret;
	}
};

//https://leetcode.com/problems/max-consecutive-ones-iii/editorial/?envType=study-plan-v2&envId=leetcode-75
class Solution {
public:
	int longestOnes(vector<int>& nums, int k) {
		int left = 0, right;
		int n = nums.size();
		for (right = 0; right < n; right++) {
			// If we included a zero in the window we reduce the value of k.
			// Since k is the maximum zeros allowed in a window.
			if (nums[right] == 0) {
				k--;
			}
			// A negative k denotes we have consumed all allowed flips and window has
			// more than allowed zeros, thus increment left pointer by 1 to keep the window size same.
			if (k < 0) {
				// If the left element to be thrown out is zero we increase k.
				k += 1 - nums[left];
				left++;
			}
		}
		return right - left;
	}
};