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

class Solution {

	int jump(vector<int>& cost, int n, int sum)
	{
		if (0 < memo.count(n))
		{
			memo[n] = std::min(memo[n], sum);
		}
		else
		{
			memo[n] = sum;
		}
		
		if (cost.size() <= n + 1 || cost.size() <= n + 2)
		{
			return sum;
		}

		int ret = std::min(
			jump(cost, n + 1, cost[n + 1] + sum),
			jump(cost, n + 2, cost[n + 2] + sum)
		);

		if (0 < memo.count(n))
		{
			memo[n] = std::min(memo[n], ret);
		}
		else
		{
			memo[n] = ret;
		}
		

		return memo[n];
	};

	unordered_map<int, int> memo;

public:
	int minCostClimbingStairs(vector<int>& cost) {

		return jump(cost, -1, 0);

	}
};