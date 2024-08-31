class Solution {
public:
	int maxVowels(string s, int k) {

		unordered_set<char> v = { 'a', 'e', 'i', 'o', 'u' };

		int count = 0;

		for (int i = 0; i < k; i++)
		{
			if (v.count(s[i]))
			{
				count++;
			}
		}

		int ret = count;
		for (int i = 1; i <= s.size() - k; i++)
		{
			if (v.count(s[i + k - 1]))
			{
				count++;
			}

			if (v.count(s[i - 1]))
			{
				count--;
			}

			ret = max(ret, count);
		}


		return ret;
	}
};


class Solution {

	bool isVowel(char c)
	{
		return vList.end() != find(vList.begin(), vList.end(), c);
	}

	static inline vector<char> vList = { 'a', 'e', 'i', 'o' , 'u' };

public:
	int maxVowels(string s, int k) {

		int max = 0;

		for (int i = 0; i < k; i++)
		{
			if (isVowel(s[i]))
				max++;
		}

		int count = max;

		for (int i = k; i < s.size(); i++)
		{
			count += isVowel(s[i - k]) ? -1 : 0;
			count += isVowel(s[i]) ? 1 : 0;

			max = std::max(max, count);
		}

		return max;
	}
};