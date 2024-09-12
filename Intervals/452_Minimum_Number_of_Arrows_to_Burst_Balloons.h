class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {

		sort(points.begin(), points.end(), [](vector<int>& l, vector<int>& r)
			{
				return l[1] < r[1];
			}
		);

		int k = points[0][1];

		int ret = 1;

		for (int i = 1; i < points.size(); i++)
		{
			if (k >= points[i][0])
			{
				continue;
			}
			else
			{
				ret++;
				k = points[i][1];
			}

		}

		return ret;
	}
};

//When you want to know if it's overlapping, you need to sort the list of locations as end points


class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {

		sort(points.begin(), points.end(), [](vector<int>& l , vector<int>& r) {
			
			if (l[1] == r[1])
			{
				return l[0] < l[0];
			}

			return l[1] < r[1];

			}
		);

		int end = points[0][1];

		int ret = 1;

		for (int i = 1; i < points.size(); i++)
		{
			if (end < points[i][0])
			{
				end = points[i][1];
				ret++;
			}
		}

		return ret;
	}
};