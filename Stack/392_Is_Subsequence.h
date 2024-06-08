class Solution {
public:
	string removeStars(string s) {

		std::stack<char> st;

		for (int i = 0; i < s.size(); i++)
			('*' != s[i]) ? st.push(s[i]) : st.pop();
	 
		string ret;
		ret.reserve(st.size());

		while (st.size())
		{
			ret.push_back(st.top());
			st.pop();
		}
		
		std::reverse(ret.begin(), ret.end());

		return ret;
	}
};