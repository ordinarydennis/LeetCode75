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

class Solution {


	void dfs(int g, int index, vector<vector<int>>& isConnected, std::unordered_map<int, vector<int>> pm)
	{

		auto& list = isConnected[index];

		for (int i = 0; i < list.size(); i++)
		{
			if (1 != list[i])
			{
				continue;
			}

			if (v[i])
			{
				continue;
			}

			pm[g].push_back(i);

			dfs(i, isConnected);
			
		}

	}

	vector<bool> v;

public:
	int findCircleNum(vector<vector<int>>& isConnected) {

		map<int, vector<int>> pm;


		int g = 0;

		for (int i = 0; i < isConnected.size(); i++)
		{
			if (v[i])
			{
				continue;
			}

			pm[g].push_back(i);

			dfs(g, i, isConnected);

			g++;
		}



		return pm.size();

	}
};

class Solution {

	void dfs(int index, vector<vector<int>>& isConnected, vector<bool>& visit, int& count)
	{
		if (visit[index])
			return;

		visit[index] = true;

		count++;

		auto& neighbor = isConnected[index];


		for (int i = 0; i < neighbor.size(); i++)
		{
			if (0 == neighbor[i])
				continue;

			if (i == index)
				continue;

			dfs(i, isConnected, visit, count);
		}

	}


public:
	int findCircleNum(vector<vector<int>>& isConnected) {

		
		vector<bool> visit(isConnected.size(), false);

		int ret = 0;

		for (int i = 0; i < isConnected.size(); i++)
		{
			int count = 0;

			dfs(i, isConnected, visit, count);

			if (count)
				ret++;
		}

		
		return ret;
	}
};