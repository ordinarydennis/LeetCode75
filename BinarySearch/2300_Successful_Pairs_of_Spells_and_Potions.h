class Solution {
public:
	vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

		vector<int> ret;

		for (double s : spells)
		{
			int c = 0;
			for (double p : potions)
			{
				if (success <= s * p)
				{
					c++;
				}
			}
			ret.push_back(c);
		}

		return ret;
	}
};


class Solution {

	int SearchIndex(int n, int start, int end,  vector<int>& potions)
	{
		if (end <= start)
		{
			return start + 1;
		}

		int m = (start + end) / 2;

		if (n == potions[m])
		{
			return m;
		}

		int ret = 0;

		if (n < potions[m])
		{
			ret = SearchIndex(n, start, m, potions);
		}
		else
		{
			ret = SearchIndex(n, m + 1, end, potions);
		}

		return ret;
	}


public:
	vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

		vector<int> ret;

		sort(potions.begin(), potions.end());

		for (double s : spells)
		{
			int c = 0;

			int f = success / s;

			f++;
		
			int index = SearchIndex(f, 0, potions.size(), potions);

			if (-1 != index)
			{
				if (potions.size() <=index)
				{
					ret.push_back(0);
				}
				else
				{
					ret.push_back(potions.size() - index);

				}
			}
		}

		return ret;
	}
};
