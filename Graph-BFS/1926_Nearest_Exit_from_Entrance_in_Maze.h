class Solution {


	void dfs(vector<vector<char>>& maze, int y, int x, vector<vector<bool>>& visited, int step, vector<int>& entrance)
	{
		if (y < 0 || maze.size() <= y)
		{
			return;
		}

		if (x < 0 || maze[0].size() <= x)
		{
			return;
		}

		if (visited[y][x])
			return;

		if ('+' == maze[y][x])
			return;

		visited[y][x] = true;

		do
		{
			if (vector<int>{ y, x } != entrance)
			{
				if (x == 0 || y == 0 || maze.size() - 1 == y || maze[0].size() - 1 == x)
				{
					ret = std::min(ret, step);
					break;
				}
			}

			dfs(maze, y - 1, x, visited, step + 1, entrance);

			dfs(maze, y + 1, x, visited, step + 1, entrance);

			dfs(maze, y, x - 1, visited, step + 1, entrance);

			dfs(maze, y, x + 1, visited, step + 1, entrance);

		} while (false);

		visited[y][x] = false;
	}

	int ret = INT_MAX;

public:
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

		vector<vector<bool>> visited(
			maze.size(), vector<bool>(maze[0].size())
		);

		int y = entrance[0];
		int x = entrance[1];

		dfs(maze, y, x, visited, 0, entrance);


		return ret == INT_MAX ? -1 : ret;
	}
};


class Solution {
public:
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

		queue<array<int, 3>> q;

		q.push({ entrance[0] , entrance[1] , 0});

		maze[entrance[0]][entrance[1]] = '+';

		vector<pair<int, int>> dir = {
			{ -1,  0 },
			{  1,  0 },
			{  0,  1 },
			{  0, -1 },
		};

		while (q.size())
		{
			auto pos = q.front();

			q.pop();

			for (auto& pa : dir)
			{
				auto y = pos[0] + pa.first;
				auto x = pos[1] + pa.second;
				auto d = pos[2] + 1;

				if (y < 0 || maze.size() <= y)
				{
					continue;
				}

				if (x < 0 || maze[0].size() <= x)
				{
					continue;
				}

				if ('+' == maze[y][x])
				{
					continue;
				}
				
				if (0 == y || maze.size() - 1 == y)
				{
					return d;
				}

				if (0 == x || maze[0].size() - 1 == x)
				{
					return d;
				}

				maze[y][x] = '+';

				q.push( { y, x, d } );
			}
		}

		return -1;
	}
};