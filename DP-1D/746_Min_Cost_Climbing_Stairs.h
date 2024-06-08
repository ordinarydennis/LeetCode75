class Solution {

	int dfs(vector<int>& cost, int index)
	{
		if (dp.count(index))
			return dp[index];

		if (cost.size() <= index)
			return 0;

		return dp[index] = 
			cost[index] + 
			std::min(
				dfs(cost, index + 1),
				dfs(cost, index + 2)
			);
	}

	unordered_map<int, int> dp;

public:
	int minCostClimbingStairs(vector<int>& cost) {

		return std::min(dfs(cost, 0), dfs(cost, 1));

	}
};