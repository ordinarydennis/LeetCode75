class Solution {
public:
	string removeStars(string s) {

		string ret;

		for (char c : s)
			('*' == c) ? ret.pop_back() : ret.push_back(c);	
		
		return ret;

	}
};