class Solution {
public:
	bool isSubsequence(string s, string t) {

		for (int a = 0, b = 0; a < s.size(); a++, b++)
		{
			while (s[a] != t[b])
			{
				b++;
				if (t.size() <= b)
				{
					return false;
				}
			}
		}

		return true;

	}
};

class Solution {
public:
	bool isSubsequence(string s, string t) {

		int sIndex = 0;

		for (int i = 0; i < t.size(); i++)
		{
			if (s[sIndex] == t[i]) sIndex++;
		}

		return s.size() == sIndex;
	}
};