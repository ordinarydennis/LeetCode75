class Solution {
public:
    int findPeakElement(vector<int>& nums) {


        for (int i = 1; i < nums.size(); i++)
        {
            if (i < nums.size() - 1)
            {
                if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
                {
                    return i;
                }
            }
            else
            {
                if (nums[i - 1] < nums[i])
                {
                    return i;
                }
            }
        }

        return 0;
    }
};


class Solution {

    int dfs(int s, int e, vector<int>& nums)
    {
        if (s == e)
        {
            return 0;
        }

        if (e - 1 == s)
        {
            return nums[s];
        }

        int m = (s + e) / 2;

        int l = dfs(s, m, nums);
        int r = dfs(m + 1, e, nums);

        if (l < nums[m] && nums[m] > r)
        {
            ret = m;
        }

        return nums[l] < nums[r] ? nums[r] : nums[l];
    }


    int ret = 0;

public:
    int findPeakElement(vector<int>& nums) {

        if (nums.size() == 2)
        {
            return nums[0] < nums[1] ? 1 : 0;
        }

        dfs(0, nums.size(), nums);

        return ret;
    }
};