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