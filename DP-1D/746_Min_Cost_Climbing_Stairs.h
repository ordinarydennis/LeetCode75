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

class Solution {

	int dfs(int n, vector<int>& cost)
	{
		if (memo.count(n))
			return memo[n];

		if (cost.size() <= n)
			return 0;
		
		int minCost = std::min(
			dfs(n + 1, cost),
			dfs(n + 2, cost)
		);


		memo[n] = cost[n] + minCost;

		return memo[n];
	}


	unordered_map<int, int> memo;

public:
	int minCostClimbingStairs(vector<int>& cost) {

		return std::min(
			dfs(0, cost), 
			dfs(1, cost)
		);

	}
};


class Solution {
	public int minCostClimbingStairs(int[] cost) {
		// The array's length should be 1 longer than the length of cost
		// This is because we can treat the "top floor" as a step to reach
		int minimumCost[] = new int[cost.length + 1];

		// Start iteration from step 2, since the minimum cost of reaching
		// step 0 and step 1 is 0
		for (int i = 2; i < minimumCost.length; i++) {
			int takeOneStep = minimumCost[i - 1] + cost[i - 1];
			int takeTwoSteps = minimumCost[i - 2] + cost[i - 2];
			minimumCost[i] = Math.min(takeOneStep, takeTwoSteps);
		}

		// The final element in minimumCost refers to the top floor
		return minimumCost[minimumCost.length - 1];
	}
}


class Solution {
	private HashMap<Integer, Integer> memo = new HashMap<Integer, Integer>();

	public int minCostClimbingStairs(int[] cost) {
		return minimumCost(cost.length, cost);
	}

	private int minimumCost(int i, int[] cost) {
		// Base case, we are allowed to start at either step 0 or step 1
		if (i <= 1) {
			return 0;
		}

		// Check if we have already calculated minimumCost(i)
		if (memo.containsKey(i)) {
			return memo.get(i);
		}

		// If not, cache the result in our hash map and return it
		int downOne = cost[i - 1] + minimumCost(i - 1, cost);
		int downTwo = cost[i - 2] + minimumCost(i - 2, cost);
		memo.put(i, Math.min(downOne, downTwo));
		return memo.get(i);
	}
}


class Solution {

	int dfs(int n, vector<int>& cost)
	{
		if (memo.count(n))
			return memo[n];

		int m = std::min(
			cost[n - 2] + dfs(n - 2, cost),
			cost[n - 1] + dfs(n - 1, cost)
		);
		
		return memo[n] = m;
	}


	unordered_map<int, int>  memo = { 
		{0, 0}, 
		{1, 0}, 
	};


public:
	int minCostClimbingStairs(vector<int>& cost) {

		return dfs(cost.size(), cost);

	}
};


class Solution {

	unordered_map<int, int> memo;

public:
	int minCostClimbingStairs(vector<int>& cost) {

		for (int i = 2; i <= cost.size(); i++)
		{
			memo[i] = std::min(
				memo[i - 1] + cost[i - 1],
				memo[i - 2] + cost[i - 2]
			);
		}

		return memo[cost.size()];
	}
};