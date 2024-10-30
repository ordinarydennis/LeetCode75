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

//brute force
class Solution {
public:
	int equalPairs(vector<vector<int>>& grid) {

		int maxY = grid.size();
		int maxX = grid[0].size();

		int ret = 0;

		for (int y = 0; y < maxY; y++)
		{
			vector<int> row;
			
			
			for (int x = 0; x < maxX; x++)
			{
				row.push_back(grid[y][x]);
			}


			for (int j = 0; j < maxX; j++)
			{
				vector<int> column;
				for (int i = 0; i < maxY; i++)
					column.push_back(grid[i][j]);

				if (row == column)
					ret++;
			}
		}

		return ret;
	}
};


class Solution {
public:
	int equalPairs(vector<vector<int>>& grid) {


		unordered_map<string, int> m;

		for (int y = 0; y < grid.size(); y++)
		{
			string s;

			for (int x = 0; x < grid[0].size(); x++)
			{
				s += to_string(grid[y][x]) + ",";
			}

			m[s]++;
		}

		int ret = 0;

		for (int x = 0; x < grid[0].size(); x++)
		{
			string s;

			for (int y = 0; y < grid.size(); y++)
			{
				s += to_string(grid[y][x]) + ",";
			}

			if (m.count(s))
			{
				ret += m[s];
			}
		}

		return ret;
	}
};