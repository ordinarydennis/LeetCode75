class Solution {

	void dfs(int index, unordered_map<int, vector<int>>& m, vector<bool>& v, int& c)
	{
		if (v[index])
			return;

		if (0 == m.count(index))
			return;

		v[index] = true;

		c++;

		for (int n : m[index])
			dfs(n, m, v, c);
	}


public:
	int findCircleNum(vector<vector<int>>& isConnected) {

		unordered_map<int, vector<int>> m;

		int n = isConnected.size();

		vector<int> p;

		for (int y = 0; y < n; y++)
		{

			for (int x = 0; x < n; x++)
			{
				if (isConnected[y][x])
				{
					p.push_back(x);
				}
			}
			m.emplace(y, std::move(p));
		}

		vector<bool> v(n);

		int ret = 0;

		for (auto& [i, p] : m)
		{
			for (int n : p)
			{
				int c = 0;

				dfs(n, m, v, c);

				if (c)
					ret++;
			}
		}

		return ret;
	}
};