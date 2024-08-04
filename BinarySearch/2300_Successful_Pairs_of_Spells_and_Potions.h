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

class Solution {
public:
	vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
		vector<pair<int, int>> sortedSpells;
		for (int i = 0; i < spells.size(); ++i) {
			sortedSpells.push_back({ spells[i], i });
		}

		// Sort the 'spells with index' and 'potions' array in increasing order.
		sort(sortedSpells.begin(), sortedSpells.end());
		sort(potions.begin(), potions.end());

		vector<int> answer(spells.size());
		int m = potions.size();
		int potionIndex = m - 1;

		// For each 'spell' find the respective 'minPotion' index.
		for (const auto& [spell, index] : sortedSpells) {
			while (potionIndex >= 0 && (long long)spell * potions[potionIndex] >= success) {
				potionIndex -= 1;
			}
			answer[index] = m - (potionIndex + 1);
		}

		return answer;
	}
};

https://leetcode.com/problems/successful-pairs-of-spells-and-potions/editorial/?envType=study-plan-v2&envId=leetcode-75


class Solution {
public:
	vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

		sort(potions.begin(), potions.end());

		vector<int> ret;

		int max = potions[potions.size() - 1];

		for (long long s : spells)
		{
			long long f = ceil(1.0 * success / s);
			
			if (f > max) {
				ret.push_back(0);
				continue;
			}

			auto index = lower_bound(potions.begin(), potions.end(), f) - potions.begin();
			ret.push_back(potions.size() - index);
		}

		return ret;
	}
};

class Solution {
public:
	vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

		sort(potions.begin(), potions.end());

		vector<int> ret;

		int max = potions[potions.size() - 1];

		for (long long s : spells)
		{
			long long f = ceil(1.0 * success / s);

			if (f > max) {
				ret.push_back(0);
				continue;
			}

			auto index = lower_bound(potions.begin(), potions.end(), f) - potions.begin();
			ret.push_back(potions.size() - index);
		}

		return ret;
	}
};


class Solution {

public:
	vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

		sort(potions.begin(), potions.end());

		vector<int> ret;

		for (long long s : spells)
		{
			int f = success / s;

			int begin = 0;
			int end = potions.size() - 1;

			while (begin < end)
			{
				int mid = begin + (end - begin) / 2;

				if (f < potions[mid])
				{
					end = mid - 1;
				}
				else
				{
					begin = mid + 1;
				}
			}

			ret.push_back(potions.size() - (end + 1));
		}

		return ret;
	}
};









