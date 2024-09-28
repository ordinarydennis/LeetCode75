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

class Solution {
public:
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

		std::queue<vector<int>> q;

		vector<vector<int>> dir = {
			{0, 1},
			{1, 0},
			{-1, 0},
			{0, -1},
		};

		int maxX = maze[0].size() - 1;
		int maxY = maze.size() - 1;

		int count = 0;

		q.push( vector<int> { entrance[0], entrance[1] } );

		while (q.size())
		{
			auto v = q.front();

			q.pop();

			int y = v[0];
			int x = v[1];

			int pushCount = 0;
			for (int i = 0; i < dir.size(); i++) 
			{
				int dy = dir[i][0] + y;
				int dx = dir[i][1] + x;

				if (dy < 0 || maxY < dy)
				{
					continue;
				}

				if (dx < 0 || maxX < dx)
				{
					continue;
				}

				if ('.' != maze[dy][dx])
				{
					continue;
				}

				if (0 == dy || maxY == dy)
				{
					return count + 1;
				}

				if (0 == dx || maxX == dx)
				{
					return count + 1;
				}

				q.push({ dy , dx });
				pushCount++;
			}

			if (pushCount)
			{
				count++;
			}	
		}
		

		return count == 0 ? -1 : count;
	}
};


class Solution {
public:
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

		std::queue<array<int, 3>> q;

		int maxX = maze[0].size() - 1;
		int maxY = maze.size() - 1;

		vector<vector<int>> dir = {
			{ 0,  1 },
			{ 0, -1 },
			{ 1,  0 },
			{-1,  0 },
		};

		maze[entrance[0]][entrance[1]] = 'e';

		q.push( { entrance[0], entrance[1], 0 } );

		while (q.size())
		{
			auto postion = q.front();

			q.pop();

			for (auto& d : dir)
			{
				int y = d[0];
				int x = d[1];

				int curY = postion[0] + y;
				int curX = postion[1] + x;
				int count = postion[2];

				if (curY < 0 || maxY < curY || curX < 0 || maxX < curX)
					continue;

				if ('.' != maze[curY][curX])
					continue;

				if (0 == curY || maxY == curY || 0 == curX || maxX == curX)
					return count + 1;
				
				maze[curY][curX] = 'v';

				q.push( { curY, curX, count + 1 } );
			}
		}

		return -1;
	}
};

class Solution {
public:
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

		queue<pair<int, vector<int>>> q;

		q.push({ 0, entrance });

		maze[entrance[0]][entrance[1]] = '+';

		vector<vector<int>> dir = {
			{ -1, 0 },
			{ 1, 0 },
			{ 0, -1 },
			{ 0, 1 },
		};


		while (q.size())
		{
			auto info = q.front();
			auto pos = info.second;

			q.pop();

			for (auto p : dir)
			{
				int y = pos[0] + p[0];
				int x = pos[1] + p[1];

				if (y < 0 || x < 0 || maze.size() == y || maze[0].size() == x)
					continue;

				if ('+' == maze[y][x])
					continue;

				if ('.' == maze[y][x])
				{
					if (0 == y || 0 == x || maze.size() - 1 == y || maze[0].size() - 1 == x)
					{
						return info.first + 1;
					}

					q.push( pair<int, vector<int>> { info.first + 1, { y, x } } );

					maze[y][x] = 'x';
				}
			}
		}

		return -1;

	}
};

