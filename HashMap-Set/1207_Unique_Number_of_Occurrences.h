class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {

		unordered_map<int, int> m;

		for (int n : arr)
			m[n]++;

		unordered_set<int> s;

		for (auto& [n, o] : m)
		{
			if (s.count(o))
				return false;

			s.insert(o);
		}

		return true;
	}
};