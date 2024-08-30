class Solution {
public:
	int equalPairs(vector<vector<int>>& grid) {

		int xMax = grid[0].size();
		int yMax = grid.size();

		int ret = 0;

		for (int x = 0; x < xMax; x++)
		{
			vector<int> column;

			for (int y = 0; y < yMax; y++)
				column.push_back(grid[y][x]);

			for (int y = 0; y < yMax; y++)
			{
				if (column == grid[y])
					ret++;
			}
		}

		return ret;
	}
};


class Solution {
public:
	int equalPairs(vector<vector<int>>& grid) {

		int n = grid.size();

		int ret = 0;

		for (int i = 0; i < n; i++)
		{
			vector<int> cList(n);

			for (int j = 0; j < n; j++)
				cList[j] = grid[j][i];

			for (int a = 0; a < n; a++)
			{
				if (cList == grid[a])
				{
					ret++;
				}
			}
		}

		return ret;
	}
};