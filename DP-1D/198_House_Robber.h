class Solution {

	int dfs(vector<int>& nums, int index)
	{
		if (memo.count(index))
			return memo[index];

		if (nums.size() <= index)
			return 0;

		memo.emplace(index,
			std::max(
				dfs(nums, index + 1),
				dfs(nums, index + 2) + nums[index]
			)
		);

		return memo[index];
	}

	unordered_map<int, int> memo;

public:
	int rob(vector<int>& nums) {

		return max(dfs(nums, 0), dfs(nums, 1));

	}
};

class Solution {

	int dfs(vector<int>& nums, int index)
	{
		if (dp.count(index))
			return dp[index];

		if (nums.size() <= index)
			return 0;

		int max = INT_MIN;

		for (int i = index; i < nums.size(); i++)
		{
			max = std::max(max,
				nums[index] + dfs(nums, i + 2)
			);
			
		}

		dp[index] = max;
		
		return max;
	}


	unordered_map<int, int> dp;

public:
	int rob(vector<int>& nums) {

		return std::max(
			dfs(nums, 0),
			dfs(nums, 1)
		);
	}
};



class Solution {

	int dfs(int index, vector<int>& nums)
	{
		if (dp.count(index))
		{
			return dp[index];
		}

		if (nums.size() <= index)
		{
			return 0;
		}


		dp[index] = max(
			dfs(index + 1, nums),
			dfs(index + 2, nums) + nums[index]
		);

		return dp[index];
	}

	unordered_map<int, int> dp;

public:
	int rob(vector<int>& nums) {

		return std::max(
			dfs(0, nums),
			dfs(1, nums)
		);
		
	}
};

class Solution {
public:
	int rob(vector<int>& nums) {

		if (nums.size() == 1) {
			return nums[0];
		}

		vector<int> dp(nums.size());

		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);

		for (int i = 2; i < nums.size(); i++)
		{
			dp[i] = std::max(
				dp[i - 2] + nums[i], 
				dp[i - 1]
			);
		}

		return dp[nums.size() - 1];
	}
};

class Solution {
public:
	int rob(vector<int>& nums) {

		if (nums.size() == 1)
		{
			return nums[0];
		}

		int dp1 = nums[0];
		int dp2 = max(nums[0], nums[1]);

		for (int i = 2; i < nums.size(); i++)
		{
			int temp = dp2;
			dp2 = std::max(dp1 + nums[i], dp2);
			dp1 = temp;
		}

		return dp2;
	}
};

class Solution {
public:
	int rob(vector<int>& nums) {

		vector<int> dp(nums.size() + 1);

		dp[nums.size() - 1] = nums[nums.size() - 1];

		for (int i = nums.size() - 2; 0 <= i; i--)
		{
			dp[i] = max(
					dp[i + 2] + nums[i],
					dp[i + 1]
				);
		}

		return dp[0];
	}
};

class Solution {
public:
	int rob(vector<int>& nums) {

		int dp1 = nums[nums.size() - 1];
		int dp2 = 0;

		for (int i = nums.size() - 2; 0 <= i; i--)
		{
			int temp = dp1;
			dp1 = max(dp2 + nums[i], dp1);
			dp2 = temp;
		}

		return dp1;
	}
};