class Solution {
public:
	int pivotIndex(vector<int>& nums) {

		for (int i = 0; i < nums.size(); i++)
		{
			int l = accumulate(nums.begin(), nums.begin() + i, 0);
			int r = accumulate(nums.begin() + i + 1, nums.end(), 0);

			if (l == r)
			{
				return i;
			}
		}

		return -1;
	}
};

class Solution {
public:
	int pivotIndex(vector<int>& nums) {

		int sum = accumulate(nums.begin(), nums.end(), 0);

		int leftSum = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			int rightSum = sum - leftSum - nums[i];
			if (leftSum == rightSum)
				return i;

			leftSum += nums[i];
		}

		return -1;
	}
};


class Solution {
public:
	int pivotIndex(vector<int>& nums) {

		vector<int> list1(nums.size());
		vector<int> list2(nums.size());

		int sum = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			sum += nums[i - 1];
			list1[i] = sum;
		}

		sum = 0;
		for (int i = nums.size() - 2; 0 <= i; i--)
		{
			sum += nums[i + 1];
			list2[i] = sum;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (list1[i] == list2[i])
			{
				return i;
			}
		}

		return -1;
	}
};


class Solution {
public:
	int pivotIndex(vector<int>& nums) {

		int sum = accumulate(nums.begin(), nums.end(), 0);

		int leftSum = 0;
		
		for (int i = 0; i < nums.size(); i++)
		{
			int rightSum = sum - leftSum - nums[i];

			if (leftSum == rightSum)
				return i;

			leftSum += nums[i];
		}

		return -1;
	}
};

class Solution {
public:
	int pivotIndex(vector<int>& nums) {

		vector<int> fix(nums.size());

		fix[0] = nums[0];

		for (int i = 1; i < fix.size(); i++)
		{
			fix[i] = nums[i] + fix[i - 1];
		}

		for (int i = 0; i < nums.size(); i++)
		{
			// right
			int r = fix[nums.size() - 1] - fix[i];

			int l = 0;

			if (0 < i)
			{
				l = fix[i - 1];
			}
			
			if (r == l)
			{
				return i;
			}
		}

		return -1;
	}
};


class Solution {
public:
	int pivotIndex(vector<int>& nums) {

		int sum = accumulate(nums.begin(), nums.end(), 0);

		int leftSum = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			int rightSum = sum - leftSum - nums[i];

			if(leftSum == rightSum)
			{
				return i;
			}

			leftSum += nums[i];
		}

		return -1;
	}
};