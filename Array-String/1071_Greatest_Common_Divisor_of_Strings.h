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

//https://leetcode.com/problems/greatest-common-divisor-of-strings/editorial/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
	bool valid(string str1, string str2, int k) {

		int len1 = str1.size(), len2 = str2.size();

		if (len1 % k > 0 || len2 % k > 0) {
			return false;
		}
		else
		{
			string base = str1.substr(0, k);

			int n1 = len1 / k, n2 = len2 / k;

			return str1 == joinWords(base, n1) && str2 == joinWords(base, n2);
		}
	}

	string joinWords(string str, int k) {

		string ans = "";

		for (int i = 0; i < k; ++i)
		{
			ans += str;
		}

		return ans;
	}


	string gcdOfStrings(string str1, string str2) {

		int len1 = str1.length(), len2 = str2.length();

		for (int i = min(len1, len2); i >= 1; --i)
		{
			if (valid(str1, str2, i))
			{
				return str1.substr(0, i);
			}
		}
		return "";
	}
};



class Solution {
public:
	string gcdOfStrings(string str1, string str2) {

		int size1 = str1.size();
		int size2 = str2.size();

		int commonSize = std::min(size1, size2);

		for (int size = commonSize; 0 < size; size--)
		{
			if (0 != size1 % size || 0 != size2 % size)
				continue;

			string commonStr = str1.substr(0, size);
			
			string substr1;
			for (int i = 0; i < size1 / size; i++)
				substr1 += commonStr;
			
			string substr2;
			for (int i = 0; i < size2 / size; i++)
				substr2 += commonStr;

			if (str1 == substr1 && str2 == substr2)
				return commonStr;

		}
			
		return "";
	}
};

class Solution {


	string check(const string& base, int count)
	{
		string ret;

		for (int i = 0; i < count; i++)
		{
			ret += base;
		}
		
		return ret;
	}


public:
	string gcdOfStrings(string str1, string str2) {

		int l = std::min(str1.size(), str2.size());

		while (0 < l)
		{
			if (str1.size() % l != 0)
			{
				l--;
				continue;
			}

			string base = str1.substr(0, l);

			if (str1 == check(base, str1.size() / l) &&
				str2 == check(base, str2.size() / l)
				)
			{
				return str1.substr(0, l);
			}

			l--;
		}
		
		return "";
	}
};

class Solution {
public:
	string gcdOfStrings(string str1, string str2) {

		if (str1 + str2 != str2 + str1)
			return "";

		return str1.substr(0, gcd(str1.size(), str2.size()));	
	}
};