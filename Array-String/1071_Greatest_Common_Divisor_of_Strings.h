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

class Solution {

	bool checkDiv(string str, string common)
	{
		int size = common.size();

		for (int b = 0; b < str.size();)
		{
			string sub2 = str.substr(b, b + size);

			if (sub2 != common)
			{
				return false;
			}

			b += size;
		}

		return true;
	}


public:
	string gcdOfStrings(string str1, string str2) {

		string ret;

		int maxSize = (str1.size() < str2.size()) ? str1.size() : str2.size();

		for (int i = 0; i < maxSize; i++)
		{
			for (int s = 1; s < maxSize; s++)
			{
				auto common = str1.substr(i, s);

				if (checkDiv(str1, common) && checkDiv(str2, common))
				{
					ret = common;
				}
			}
		}

		return ret;
	}
};