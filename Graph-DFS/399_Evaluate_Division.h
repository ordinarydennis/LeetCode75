class Solution {

	void dfs(const string& target, const string& str, double v, unordered_map<string, unordered_map<string, double>>& m)
	{
		if (target == str)
		{
			ret.push_back(v);
			return;
		}

		if (0 == m.count(str))
		{
			ret.push_back(-1.0);
			return;
		}

		unordered_map<string, double>& cm = m[str];

		for (auto& [s, v2] : cm)
		{
			dfs(target, s, v * v2, m, visit);
		}
	}

	vector<double> ret;

public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

		unordered_map<string, unordered_map<string, double>> m;

		unordered_set<string> visit;

		for (int i = 0;i < equations.size(); i++)
		{
			m[equations[i][0]][equations[i][1]] = values[i];
			m[equations[i][1]][equations[i][0]] = 1.0 / values[i];
		}

		for (int i = 0; i < queries.size(); i++)
		{
			auto& t = queries[i][0];
			auto& s = queries[i][1];

			dfs(t, s, 1.0, m, visit);
		}

		return ret;
	}
};