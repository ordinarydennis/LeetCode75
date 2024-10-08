
//fail
class Solution {
public:
	string decodeString(string s) {


		stack<int> intSt;
		stack<string> strSt;

		int times = 0;
		int r = 1;

		string ret;

		string str;

		for(int i = 0; i < s.size(); i++)
		{
			char c = s[i];

			if ('1' <= c && c <= '9')
			{
				times = (times * r) + (c - '0');
				r = r * 10;
			}

			if ('[' == s[i])
			{
				intSt.push(times);
				times = 0;
				r = 1;

				if (str.size())
				{
					strSt.push(str);
					str.clear();
				}
			}
			else if ('a' <= c && c <= 'z')
			{
				str.push_back(c);
			}
			else if (']' == c)
			{
				if (str.size())
				{
					strSt.push(str);
					str.clear();
				}

				int repeat = intSt.top();
				intSt.pop();
				auto str2 = strSt.top();
				strSt.pop();

				string s;
				for (int i = 0; i < repeat; i++)
					s += str2;

				ret += s;
			}
		}

		if (str.size())
		{
			ret += str;
		}

		return ret;
	}
};

class Solution {
public:
	string decodeString(string s) {

		std::stack<char> cSt;

		for (int i = 0; i < s.size(); i++)
		{
			char c = s[i];

			if (']' == c)
			{
				string str;

				while ('[' != cSt.top())
				{
					str += cSt.top();
					cSt.pop();
				}

				cSt.pop();

				int repeat = 0;
				int base = 1;

				while (cSt.size() && isdigit(cSt.top()))
				{
					repeat = (cSt.top() - '0') * base + repeat;
					base = base * 10;
					cSt.pop();
				}

				while (repeat--)
				{
					for (int i = str.size() - 1; 0 <= i; i--)
						cSt.push(str[i]);
				}
			}
			else
			{
				cSt.push(c);
			}
		}

		string ret;

		while (cSt.size())
		{
			ret = cSt.top() + ret;
			cSt.pop();
		}

		return ret;
	}
};