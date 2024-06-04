class Solution {
public:
	string gcdOfStrings(string str1, string str2) {

		for (int i = 1; i <= str2.size(); i++)
		{
			int k = 0;

			int result = true;

			while (str2.substr(0, i) == str1.substr(k, i))
			{
				k += i;

				if (str1.size() <= k)
				{
					result = false;
					break;
				}
			}

			if (result)
			{
				return str2.substr(0, i);
			}
		}

		return "";
	}
};