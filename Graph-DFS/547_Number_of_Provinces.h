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



//bfs
class Solution {
public:
	int findCircleNum(vector<vector<int>>& isConnected) {

		vector<bool> v(isConnected.size(), false);

		int ret = 0;

		for (int i = 0; i < isConnected.size(); i++)
		{
			if (v[i])
				continue;

			ret++;

			queue<int> q;

			q.push(i);

			while (q.size())
			{
				auto node = q.front();

				q.pop();

				v[node] = true;

				for (int n = 0; n < isConnected[node].size(); n++)
				{
					if (0 == isConnected[node][n] || v[n])
					{
						continue;
					}
					
					q.push(n);

				}
			}
		}


		return ret;
	}
};

class Solution {

	void dfs(int index, unordered_map<int, vector<int>>& m, int& count)
	{
		if (visit[index])
		{
			return;
		}

		visit[index] = true;

		count++;

		auto ns = m[index];

		for (auto n : ns)
		{
			dfs(n, m, count);
		}
	}

	int ret = 0;

	vector<bool> visit;

public:
	int findCircleNum(vector<vector<int>>& isConnected) {

		unordered_map<int, vector<int>> m;

		visit.resize(isConnected.size());

		for (int y = 0; y < isConnected.size(); y++)
		{
			for (int x = 0; x < isConnected[0].size(); x++)
			{
				if (isConnected[y][x])
				{
					m[y].push_back(x);
				}
			}
		}

		for (int i = 0; i < isConnected.size(); i++)
		{
			int count = 0;
			dfs(i, m, count);
			if (count)
				ret++;
		}

		return ret;
	}
};


class Solution {
public:
	void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
		visit[node] = true;
		for (int i = 0; i < isConnected.size(); i++) {
			if (isConnected[node][i] && !visit[i]) {
				dfs(i, isConnected, visit);
			}
		}
	}

	int findCircleNum(vector<vector<int>>& isConnected) {
		int n = isConnected.size();
		int numberOfComponents = 0;
		vector<bool> visit(n);

		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				numberOfComponents++;
				dfs(i, isConnected, visit);
			}
		}

		return numberOfComponents;
	}
};

class Solution {

	void dfs(int index, vector<vector<int>>& isConnected, vector<bool>& visit)
	{
		visit[index] = true;

		auto ns = isConnected[index];

		for (int i = 0; i < ns.size(); i++)
		{
			if (ns[i] && !visit[i])
			{
				dfs(i, isConnected, visit);
			}
		}
	}


public:
	int findCircleNum(vector<vector<int>>& isConnected) {

		int ret = 0;

		vector<bool> visit(isConnected.size());

		for (int i = 0; i < isConnected.size(); i++)
		{
			if (!visit[i])
			{
				ret++;
				dfs(i, isConnected, visit);
			}
		}

		return ret;
	}
};