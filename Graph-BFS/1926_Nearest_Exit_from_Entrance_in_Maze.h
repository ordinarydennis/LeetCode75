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