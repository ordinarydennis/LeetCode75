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


class Solution {

	int dfs(int s, int e, vector<int>& nums)
	{
		if (s == e)
			return s;

		int m = (s + e) / 2;

		if (nums[m] > nums[m + 1])
			return dfs(s, m, nums);
		else
			return dfs(m + 1, e, nums);
	}

public:
	int findPeakElement(vector<int>& nums) {

		return dfs(0, nums.size() - 1, nums);

	}
};

class Solution {
public:
	int findPeakElement(vector<int>& nums) {

		int l = 0, r = nums.size() - 1;

		while (l < r)
		{
			int mid = (l + r) / 2;

			if (nums[mid] > nums[mid + 1])
				r = mid;
			else
				l = mid + 1;
		}
		return l;
	}
};



class Solution {
public:
    int findPeakElement(vector<int>& nums) {

		for (int i = 0; i < nums.size(); i++)
		{
			bool l = true;

			if (0 <= i - 1)
			{
				l = nums[i - 1] <= nums[i];
			}

			bool r = true;
			if (i + 1 < nums.size())
			{
				r = nums[i + 1] <= nums[i];
			}

			if (l && r)
			{
				return i;
			}
		}

		return 0;
    }
};



class Solution {
public:
	int findPeakElement(vector<int>& nums) {

		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				return i;
			}
		}

		return nums.size() - 1;
	}
};

class Solution {

	int dfs(vector<int>& nums, int l , int r)
	{
		if (l == r)
			return l;

		int m = (l + r) / 2;

		return (nums[m] < nums[m + 1]) ? dfs(nums, m + 1, r) : dfs(nums, l, m);
	}


public:
	int findPeakElement(vector<int>& nums) {

		return dfs(nums, 0, nums.size() - 1);

	}
};

