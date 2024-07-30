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


