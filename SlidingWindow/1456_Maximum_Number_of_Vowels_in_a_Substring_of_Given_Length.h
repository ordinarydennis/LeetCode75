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