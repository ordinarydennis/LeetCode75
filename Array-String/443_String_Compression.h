ccclass Solution{
public:
	int compress(vector<char>&chars) {

		if (chars.size() == 1)
		{
			return 1;
		}

		int count = 1;

		vector<char> str;

		for (int i = 1; i <= chars.size(); i++)
		{
			if (i == chars.size() || chars[i] != chars[i - 1])
			{
				str.push_back(chars[i - 1]);

				if (1 < count)
				{
					auto nStr = to_string(count);

					for (int a = 0; a < nStr.size(); a++)
						str.push_back(nStr[a]);
				}

				count = 1;
			}
			else
			{
				count++;
			}
		}

		chars = str;

		return static_cast<int>(str.size());
	}
};


class Solution {
public:
	int compress(vector<char>& chars) {

		unordered_map<char, int> m;

		for (int i = 0; i < chars.size(); i++)
		{
			char c = chars[i];
			m[c]++;
		}

		int size = 0;

		for (int i = 0; i < chars.size();)
		{
			if (m.empty())
			{
				break;
			}

			char c = chars[i];

			if (1 < m[c])
			{
				string str = to_string(m[c]);

				for (int a = 0; a < str.size(); a++)
				{
					chars[i + a + 1] = str[a];
				}

				i += str.size() + 1;
			}
			else
			{
				i++;
			}

			m.erase(c);

			size = i;
		}

		return size;
	}
};

class Solution {
public:
	int compress(vector<char>& chars) {

		if (1 == chars.size())
			return 1;

		char pre = chars[0];
		int count = 1;

		string str;

		int i = 1;

		for (; i < chars.size(); i++)
		{
			char c = chars[i];

			if (pre == c)
			{
				count++;
			}
			else
			{
				if (1 < count)
				{
					str = to_string(count);

					for (int a = 0; a < str.size(); a++)
					{
						chars[i - count + a + 1] = str[a];
					}
				}

				count = 1;
				pre = c;
			}
		}

		if (0 < count)
		{
			str = to_string(count);

			for (int a = 0; a < str.size(); a++)
			{
				chars[i - count + a + 1] = str[a];
			}
		}

		return i - count + str.size() + 1;

	}
};


class Solution {
public:
	int compress(vector<char>& chars) {


		int pos = 0;
	
		for (int i = 0; i < chars.size(); i++)
		{
			char c = chars[i];

			int count = 1;

			while (i + l -1 < chars.size() && chars[i] == chars[i + count])
			{
				count++;
			}

			string str;

			if (1 < count)
			{
				string str = to_string(count);

				for (char c : str)
				{
					chars[pos] = c;
				}

				count = 1;
			}	
		}

	}
};


class Solution {
public:
	int compress(vector<char>& chars) {

		int r = 0;

		for (int i = 0; i < chars.size();)
		{
			char c = chars[i];

			int start = i;

			while(i + 1 < chars.size() && chars[i] == chars[i + 1])
				i++;

			int l = i - start + 1;

			chars[r] = c;

			r++;

			if (1 < l)
			{
				auto lstr = to_string(l);

				for (int p = 0; p < lstr.size(); p++)
				{
					chars[r + p] = lstr[p];
				}

				r += lstr.size();
			}

			i++;
		}

		return r;
	}
};


class Solution {
public:
	int compress(vector<char>& chars) {

		string s;

		char pre = chars[0];
		int count = 1;

		for (int i = 1; i <= chars.size(); i++)
		{
			if (i == chars.size())
			{
				s.push_back(pre);
				if (1 < count)
				{
					s += to_string(count);
				}
				break;
			}

			if (pre == chars[i])
			{
				count++;
			}
			else
			{
				s.push_back(pre);
				if (1 < count)
				{
					s += to_string(count);
				}
				pre = chars[i];
				count = 1;
			}
			
		}

		chars.clear();

		for (int i= 0; i < s.size(); i++)
		{
			chars.push_back(s[i]);
		}

		return s.size();
	}
};
