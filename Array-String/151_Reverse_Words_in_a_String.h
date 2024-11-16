class Solution {
public:
    string reverseWords(string s) {

        vector<string> list;

        string temp;

        for (int i = 0; i <= s.size(); i++)
        {
            if (i == s.size()  || ' ' == s[i])
            {
                if (temp.size())
                {
                    list.emplace_back(std::move(temp));
                }
            }
            else
            {
                temp.push_back(s[i]);
            }
        }

        string ret;

        if (list.size())
        {
            for (auto it = list.rbegin(); it != list.rend(); ++it)
            {
                ret += *it + " ";
            }
        }

        ret.pop_back();

        return ret;
    }
};

//if the input string size is n,
//time complexity O(n)

//If the result string size is m, 
//space complexity O(m)


class Solution {
public:
	string reverseWords(string s) {

		vector<string> sList;

		string str;

		for (int i = 0; i <= s.size(); i++)
		{
			if (i == s.size() && str.size())
			{
				sList.push_back(std::move(str));
				break;
			}

			if (' ' == s[i])
			{
				if (str.size())
				{
					sList.push_back(std::move(str));
				}
			}
			else
			{
				str += s[i];
			}
		}

		string ret;

		for (auto it = sList.rbegin(); it != sList.rend(); ++it)
		{
			ret += *it + " ";
		}

		ret.pop_back();

		return ret;
	}
};

class Solution {
public:
	string reverseWords(string s) {

		std::stack<string> st;

		string str;

		for (int i = 0; i <= s.size(); i++)
		{
			if (i == s.size() && str.size())
			{
				st.push(std::move(str));
				break;
			}
			if (' ' == s[i])
			{
				if (str.size())
				{
					st.push(std::move(str));
				}	
			}
			else
			{
				str += s[i];
			}
		}


		string ret;

		while (st.size())
		{
			ret += st.top() + " ";
			st.pop();
		}

		ret.pop_back();

		return ret;
	}
};


class Solution {
public:
	string reverseWords(string s) {


		string str;

		vector<string> list;

		for (int i = 0; i <= s.size(); i++)
		{
			if(' ' == s[i] || i == s.size())
			{
				if (!str.empty())
				{
					list.emplace_back(std::move(str));
				}
			}
			else
			{
				str += s[i];
			}
		}


		string ret;

		for (auto str : list)
		{
			ret = str + " " + ret;
		}

		ret.pop_back();

		return ret;

	}
};

