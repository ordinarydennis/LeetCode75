class Solution {
public:
	int longestSubarray(vector<int>& nums) {

		int count = 0;

		int left = 0;
		int right = 0;

		for (; right < nums.size(); right++)
		{
			if (0 == nums[right])
			{
				count++;
			}

			if (1 < count)
			{
				if (0 == nums[left])
				{
					count--;
				}
				left++;
			}
		}

		return right - left - 1;
	}
};

class Solution {
public:
	int longestSubarray(vector<int>& nums) {

		int zCount = 0;

		int left = 0; 

		int ret = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (0 == nums[i])
			{
				zCount++;
			}

			if (zCount <= 1)
			{
				ret = max(ret, i - left + 1);
			}

			if (1 < zCount)
			{
				while(1 == nums[left])
				{
					left++;
				}

				left++;
				zCount--;
			}
	  
		}

		return ret - 1;
	}
};

class Solution {
public:
	int longestSubarray(vector<int>& nums) {

		int zCount = 0;
		int start = 0;
		int ret = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			zCount += (0 == nums[i]) ? 1 : 0;

			while (1 < zCount)
			{
				zCount -= (nums[start] == 0) ? 1 : 0;
				start++;
			}

			ret = max(ret, i - start);
		}

		return ret;
	}
};


class Solution {
public:
	int longestSubarray(vector<int>& nums) {

		int max = 0;
		int remain = 1;
		int left = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (0 == nums[i])
			{
				if (1 == remain)
				{
					remain--;
				}
				else
				{
					while (1 == nums[left])
					{
						left++;
					}
					left++;
					remain++;
				}
			}

			max = std::max(max, i - left);
		}

		return max - 1;
	}
};
