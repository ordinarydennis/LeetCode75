class Solution {

	void dfs(int index, vector<bool>& v, unordered_map<int, vector<int>>& km)
	{
		if (v[index])
			return;

		if (0 == km.count(index))
			return;

		v[index] = true;

		for (int n : km[index])
			dfs(n, v, km);
	}


public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		
		vector<bool> visited(rooms.size());

		unordered_map<int, vector<int>> km;

		for (int i = 0; i < rooms.size(); i++)
			km.emplace(i, std::move(rooms[i]));

		dfs(0, visited, km);

		return visited.end() == std::find(visited.begin(), visited.end(), false);
	}
};

class Solution {

private:

	void dfs(vector<vector<int>>& rooms, int index)
	{
		if (visit[index])
			return;

		visit[index] = true;

		auto keyList = rooms[index];

		for (int k : keyList)
			dfs(rooms, k);
	}

	vector<bool> visit;

public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {

		visit.resize(rooms.size(), false);

		dfs(rooms, 0);

		return visit.end() == find(visit.begin(), visit.end(), false);

	}
};




class Solution {

	void dfs(int index, vector<vector<int>>& rooms, vector<bool>& visit)
	{
		if (visit[index])
			return;

		visit[index] = true;

		auto keys = rooms[index];

		for (int i = 0; i < keys.size(); i++)
		{
			int key = keys[i];

			if (index == key)
			{
				continue;
			}

			dfs(key, rooms, visit);
		}
	}

public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {

		vector<bool> visit(rooms.size());

		dfs(0, rooms, visit);

		return visit.end() == find(visit.begin(), visit.end(), false);
	}
};



class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {

		stack<int> st;

		for (int i = 0; i < rooms[0].size(); i++)
		{
			st.push(rooms[0][i]);
		}

		vector<bool> visit(rooms.size());

		visit[0] = true;

		while (!st.empty())
		{
			int key = st.top();

			st.pop();

			if (visit[key])
			{
				continue;
			}

			visit[key] = true;

			for (int i = 0; i < rooms[key].size(); i++)
			{
				if (visit[rooms[key][i]] || key == rooms[key][i])
					continue;

				st.push(rooms[key][i]);
			}
		}

		return visit.end() == find(visit.begin(), visit.end(), false);
	}
};
