class Solution {
public:
	string gcdOfStrings(string str1, string str2) {

		if (str1 == str2)
			return str1;

		string common = str1.size() < str2.size() ? str1 : str2;
		string target = str1.size() < str2.size() ? str2 : str1;

		

		while (size)
		{
			int begin = 0;

			if (0 != target.size() % common.size())
			{
				common.pop_back();
				continue;
			}

			int size = common.size();
			
			while(begin < target.size())
			{
				auto sub = target.substr(begin, size);

				if (common != sub)
				{
					break;
				}

				begin += size;
			}

			if (begin == target.size())
			{
				return common;
			}

			common.pop_back();
		}

		return "";
	}
};

class Solution {

	bool isDivided(const string& target, string common)
	{
		int size = common.size();

		while (size)
		{
			int begin = 0;

			if (0 != target.size() % common.size())
			{
				common.pop_back();
				size--;
				continue;
			}

			while (begin < target.size())
			{
				auto sub = target.substr(begin, size);

				if (common != sub)
				{
					break;
				}

				begin += size;
			}

			if (begin == target.size())
			{
				return true;
			}

			common.pop_back();
			size--;
		}

		return false;
	}

public:
	string gcdOfStrings(string str1, string str2) {

		int size = 1;

		int max = 0;

		while(size < str1.size() && size < str2.size())
		{
			if (isDivided(str1, str1.substr(0, size)) && 
				isDivided(str2, str2.substr(0, size))
				)
			{
				max = size;
			}
		}



		return 0 == max ? "" : str1.substr(0, max);

	}
};