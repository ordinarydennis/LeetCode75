class Solution {


	void dfs(int index, unordered_map<int, vector<pair<int, int>>>& m, vector<int>& v, int& ret)
	{
		if (0 == m.count(index))
		{
			return;
		}

		if (v[index])
		{
			return;
		}

		v[index] = true;

		for (auto& p : m[index])
		{
			if (-1 == p.second)
			{
				ret++;
			}
			
			dfs(p.first, m, v, ret);
		}
	}


public:
	int minReorder(int n, vector<vector<int>>& connections) {

		unordered_map<int, vector<pair<int, int>>> m;

		vector<int> v(n);

		for (auto& p : connections)
		{
			m[p[1]].push_back(pair<int, int>{ p[0] , 1 });
			m[p[0]].push_back(pair<int, int>{ p[1] , 0 });   
		}

		int ret = 0;

		dfs(0, m, v, ret);

		return ret;
	}
};

class Solution {

	int ret = 0;

	void dfs(int index, int parent, vector<vector<pair<int, int>>>& g)
	{
		for(const auto& [node, sign] : g[index])
		{ 
			if (parent != node)
			{
				ret += sign;
				dfs(node, index, g);
			}
		}
	}


public:
	int minReorder(int n, vector<vector<int>>& connections) {

		vector<vector<pair<int,int>>> g(n);

		for (const auto& p : connections)
		{
			g[p[0]].push_back({ p[1], 1 });
			g[p[1]].push_back({ p[0], 0 });
		}

		dfs(0, -1, g);

		return ret;
	}
};

//leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/editorial/?envType=study-plan-v2&envId=leetcode-75