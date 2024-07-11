class Solution {

	int dfs(int y, int x, pair<int, int>& dest, vector<vector<int>>& dp)
	{
		if (dest.first <= y || dest.second <= x)
			return 0;

		if (0 < dp[y][x])
			return dp[y][x];

		if (y == dest.first - 1 && x == dest.second - 1)
			return 1;

		return dp[y][x] = dfs(y + 1, x, dest, dp) + dfs(y, x + 1, dest, dp);
	}


public:
	int uniquePaths(int m, int n) {

		if (m == 1 && n == 1)
			return 1;

		pair<int, int> dest = { m, n };

		vector<vector<int>> dp(m, vector<int>(n));

		dfs(0, 0, dest, dp);

		return dp[0][0];
	}
};