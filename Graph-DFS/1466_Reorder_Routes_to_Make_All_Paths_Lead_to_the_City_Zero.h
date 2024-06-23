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