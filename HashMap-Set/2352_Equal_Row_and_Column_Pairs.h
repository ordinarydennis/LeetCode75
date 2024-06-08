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