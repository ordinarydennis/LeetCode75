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


class Solution {
public:
	int minReorder(int n, vector<vector<int>>& connections) {

		unordered_map<int, vector<pair<int, int>>> m;

		for (int i = 0; i < connections.size(); i++)
		{
			auto& e = connections[i];

			m[e[0]].push_back({ e[1] , 1 });
			m[e[1]].push_back({ e[0] , -1 });
		}

		queue<int> q;

		q.push(0);

		int ret = 0;

		vector<int> v(connections.size() + 1);

		while (q.size())
		{
			int t = q.front();

			q.pop();

			v[t] = true;

			for (int i = 0; i < m[t].size(); i++)
			{
				if (false == v[m[t][i].first])
				{
					if (1 == m[t][i].second)
					{
						ret++;
					}

					q.push(m[t][i].first);
				}
			}	
		}

		return ret;
	}
};

class Solution {

	void dfs(int index, unordered_map<int, vector<pair<int, int>>>& m, vector<bool>& v)
	{
		if (v[index])
			return;

		v[index] = true;
		
		auto& neighbor = m[index];

		for (int i = 0; i < neighbor.size(); i++)
		{
			if (false == v[neighbor[i].first])
			{
				ret += neighbor[i].second;
				dfs(neighbor[i].first, m, v);
			}
		
		}
	}


	int ret = 0;

public:
	int minReorder(int n, vector<vector<int>>& connections) {

		unordered_map<int, vector<pair<int, int>>> m;

		vector<bool> v(connections.size() + 1);

		for (int i = 0; i < connections.size(); i++)
		{
			m[connections[i][0]].push_back({ connections[i][1], 1 });
			m[connections[i][1]].push_back({ connections[i][0], 0 });
		}

		dfs(0, m, v);

		return ret;
	}
};

class Solution {


	void dfs(int node, unordered_map<int, unordered_map<int, int>>& mm, vector<bool>& v)
	{
		if (v[node])
		{
			return;
		}

		v[node] = true;

		auto ne = mm[node];

		for (auto& [n, d] : ne)
		{
			if (!v[n])
			{
				ret += d;
				dfs(n, mm, v);
			}
		}
	}

	int ret = 0;


public:
	int minReorder(int n, vector<vector<int>>& connections) {

		unordered_map<int, unordered_map<int, int>> mm;

		for (auto connect : connections)
		{
			mm[connect[0]][connect[1]] = 1;
			mm[connect[1]][connect[0]] = 0;
		}

		vector<bool> v(n);

		dfs(0, mm, v);

		return ret;
	}
};

