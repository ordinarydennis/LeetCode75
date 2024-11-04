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

class Solution {
public:
	int longestOnes(vector<int>& nums, int k) {

		int start = 0;
		int ret = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (0 == nums[i])
			{
				if (0 < k)
				{
					k--;
				}
				else
				{
					while (1 == nums[start])
						start++;

					start++;
				}
				
			}

			ret = max(ret, i - start + 1);
		}

		return ret;
	}
};

//1, 1, 1, 0, 0, 0, 0, 0, 0
//
//   1, 1, 0, 0, 0,						-> k = -1
//	  1, 0, 0, 0, 0						-> k = -2
//	     0, 0, 0, 0, 0					-> k = -3
//			0, 0, 0, 0, 0				-> k = -3
// k가 음수가 되면 윈도우의 크기(right - left)는 계속 유지가 된다. 
// 윈도우의 크기 : 우리가 찾는 최대 길이가 된다.



class Solution {
public:
	int longestOnes(vector<int>& nums, int k) {

		int ret = 0;

		int left = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (0 == nums[i])
			{
				if (0 < k)
				{
					k--;
				}
				else
				{
					while (1 == nums[left])
					{
						left++;
					}

					left++;
				}
			}

			ret = max(ret, i - left + 1);
		}

		return ret;
	}
};
