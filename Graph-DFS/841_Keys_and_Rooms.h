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