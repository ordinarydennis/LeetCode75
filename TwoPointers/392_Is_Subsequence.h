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


class Solution {
public:
	bool isSubsequence(string s, string t) {

		if (s.empty())
		{
			return true;
		}

		if (t.size() < s.size())
		{
			return false;
		}

		int sIndex = 0;

		for(int i = 0; i < t.size(); i++)
		{
			if (s[sIndex] == t[i])
			{
				sIndex++;
				if (s.size() <= sIndex)
				{
					return true;
				}
			}
		}

		return false;
	}
};

class Solution {
	String source, target;
	Integer leftBound, rightBound;

	private boolean rec_isSubsequence(int leftIndex, int rightIndex) {
		// base cases
		if (leftIndex == leftBound)
			return true;
		if (rightIndex == rightBound)
			return false;

		// consume both strings or just the target string
		if (source.charAt(leftIndex) == target.charAt(rightIndex))
			++leftIndex;
		++rightIndex;

		return rec_isSubsequence(leftIndex, rightIndex);
	}

	public boolean isSubsequence(String s, String t) {
		this.source = s;
		this.target = t;
		this.leftBound = s.length();
		this.rightBound = t.length();

		return rec_isSubsequence(0, 0);
	}
}

class Solution {

	public boolean isSubsequence(String s, String t) {
		Integer leftBound = s.length(), rightBound = t.length();
		Integer pLeft = 0, pRight = 0;

		while (pLeft < leftBound && pRight < rightBound) {
			// move both pointers or just the right pointer
			if (s.charAt(pLeft) == t.charAt(pRight)) {
				pLeft += 1;
			}
			pRight += 1;
		}
		return pLeft == leftBound;
	}
}

class Solution {
public:
	bool isSubsequence(string s, string t) {

		unordered_map<char, vector<int>> map;

		for (int i = 0; i < t.size(); i++)
		{
			map[t[i]].push_back(i);
		}

		int curIndex = -1;

		for (int i = 0; i < s.size(); i++)
		{
			if (0 == map.count(s[i]))
			{
				return false;
			}

			auto v = map[s[i]];

			int isFound = false;

			for (int index : v)
			{
				if (curIndex < index)
				{
					isFound = true;
					curIndex = index;
					break;
				}
			}

			if (!isFound)
			{
				return false;
			}
		}

		return true;
	}
};