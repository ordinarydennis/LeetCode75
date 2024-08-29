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

class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {

		std::unordered_map<int, int> m;

		for (int i = 0; i < arr.size(); i++)
		{
			m[arr[i]]++;
		}


		std::unordered_set<int> oSet;

		for (auto& [n, o] : m)
		{
			if (oSet.count(o))
			{
				return false;
			}

			oSet.insert(o);
		}

		return true;

	}
};