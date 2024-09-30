class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {

		int xm = grid[0].size();
		int ym = grid.size();

		queue<array<int, 2>> pos;

		vector<array<int, 2>> dir = {
			{ -1,  0 },
			{  1,  0 },
			{  0,  1 },
			{  0, -1 }

		};

		int ret = 0;

		for (int y = 0; y < ym; y++)
		{
			for (int x = 0; x < xm; x++)
			{
				if (0 == grid[y][x] || 1 == grid[y][x])
					continue;

				pos.push({ y, x });
			}
		}

		while (pos.size())
		{
			int size = pos.size();

			int n = 0;

			for (int i = 0; i < size; i++)
			{
				auto p = pos.front();

				pos.pop();

				int y = p[0];
				int x = p[1];

				for (auto& d : dir)
				{
					int cy = y + d[0];
					int cx = x + d[1];

					if (cy < 0 || ym <= cy ||
						cx < 0 || xm <= cx)
						continue;

					if (2 == grid[cy][cx] || 0 == grid[cy][cx])
						continue;

					grid[cy][cx] = 2;
					pos.push({ cy, cx });
					n++;
				}
			}

			if (n)
				ret++;
		}

		for (int y = 0; y < ym; y++)
		{
			for (int x = 0; x < xm; x++)
			{
				if (1 == grid[y][x])
					return -1;
			}
		}

		return ret;
	}
};

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {

		queue<array<int, 2>> q;

		int freshOrangeCount = 0;

		for (int y = 0; y < grid.size(); y++)
		{
			for (int x = 0; x < grid[0].size(); x++)
			{
				if(2 == grid[y][x])
				{ 
					q.push({ y, x });
				}
				else if (1 == grid[y][x])
				{
					freshOrangeCount++;
				}
			}
		}

		if (0 == freshOrangeCount)
		{
			return 0;
		}

		int ret = 0;

		vector<vector<int>> dir = {
			{1, 0},
			{-1, 0},
			{0, 1},
			{0, -1},
		};


		int maxX = grid[0].size() - 1;
		int maxY = grid.size() - 1;

		while (q.size())
		{
			bool b = false;

			int size = q.size();

			for (int i = 0; i < size; i++)
			{

				auto o = q.front();

				q.pop();

				int y = o[0];
				int x = o[1];

				for (auto d : dir)
				{
					int dy = d[0] + y;
					int dx = d[1] + x;

					if (dy < 0 || maxY < dy)
					{
						continue;
					}

					if (dx < 0 || maxX < dx)
					{
						continue;
					}

					if (1 == grid[dy][dx])
					{
						grid[dy][dx] = 2;
						q.push({ dy, dx });
						freshOrangeCount--;
					}
				}
			}

			ret++;
		}

		return 0 < freshOrangeCount ? -1 : ret - 1;
	}
};


class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {

		queue<vector<int>> q;

		int totalFCount = 0;

		int yMax = grid.size();
		int xMax = grid[0].size();

		for (int y = 0; y < yMax; y++)
		{
			for (int x = 0; x < xMax; x++)
			{
				if (2 == grid[y][x])
				{
					q.push(vector<int>{ y, x, 0 });
				}
				else if (1 == grid[y][x])
				{
					totalFCount++;
				}
			}
		}

		vector<vector<int>> dir = {
			{ -1, 0 },
			{ 1,  0 },
			{ 0, -1 },
			{ 0,  1 },
		};


		while (!q.empty())
		{
			auto s = q.size();

			for (int i = 0; i < s; i++)
			{
				auto info = q.front();

				q.pop();

				int y = info[0];
				int x = info[1];
				int m = info[2];

				for (auto d : dir)
				{
					int y2 = d[0];
					int x2 = d[1];

					int cY = y + y2;
					int cX = x + x2;

					if (cY < 0 || cX < 0 || xMax <= cX || yMax <= cY)
					{
						continue;
					}

					if (1 == grid[cY][cX])
					{
						grid[cY][cX] = 2;
						totalFCount--;
						q.push(vector<int>{ cY, cX, m + 1 });

						if (0 == totalFCount)
						{
							return m + 1;
						}
					}
				}
			}
		}

		return  (0 < totalFCount) ? -1 : 0;
	}
};
