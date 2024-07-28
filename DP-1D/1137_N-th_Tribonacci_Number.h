class Solution {
public:
	int tribonacci(int n) {

		if (0 == n)
			return 0;
		else if (n <= 2)
			return 1;

		int t0 = 0;
		int t1 = 1;
		int t2 = 1;

		int ret = 0;
		for (int i = 3; i <= n; i++)
		{
			ret = t0 + t1 + t2;

			int temp = t0;
			t0 = t1;
			t1 = t2;
			t2 = ret;
		}

		return ret;
	}
};

class Solution {

	int dfs(int n)
	{
		if (m.count(n))
			return m[n];

		m[n] = dfs(n - 3) + dfs(n - 2) + dfs(n - 1);

		return m[n];
	}

	unordered_map<int, int> m = { {0, 0}, {1, 1}, {2, 1} };

public:
	int tribonacci(int n) {

		return dfs(n);
	}
};

class Solution {

	int dfs(int n)
	{
		if (-1 != memo[n])
		{
			return memo[n];
		}

		if (0 == n)
		{
			return 0;
		}

		if (n == 1 || n == 2)
		{
			return 1;
		}

		memo[n] = dfs(n - 1) + dfs(n - 2) + dfs(n - 3);

		return memo[n];

	}


	vector<int> memo;

public:
	int tribonacci(int n) {

		memo.resize(n + 1, -1);

		return dfs(n);

	}
};


class Solution {


public:
	int tribonacci(int n) {

		if (n == 0)
			return 0;

		if (n <= 2)
			return 1;

		int ret = 0;

		int a = 0;
		int b = 1;
		int c = 1;

		for (int i = 3; i <= n; i++)
		{
			ret = a + b + c;

			a = b;
			b = c;
			c = ret;
		}


		return ret;
	}
};
