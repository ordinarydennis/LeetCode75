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