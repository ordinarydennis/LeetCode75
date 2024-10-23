class Solution {
public:
	string removeStars(string s) {

		string ret;

		for (char c : s)
			('*' == c) ? ret.pop_back() : ret.push_back(c);	
		
		return ret;

	}
};

//stack
class Solution {
public:
	string removeStars(string s) {

		std::stack<char> st;

		for (char c : s)
			('*' == c) ? st.pop() : st.push(c);

		string ret;

		while (st.size())
		{
			ret.push_back(st.top());
			st.pop();
		}

		reverse(ret.begin(), ret.end());

		return ret;
	}
};

//two pointer
class Solution {
public:
	string removeStars(string s) {
		vector<char> ch(s.size());
		int j = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '*') {
				j--;
			}
			else {
				ch[j++] = s[i];
			}
		}

		string answer = "";
		for (int i = 0; i < j; i++) {
			answer.push_back(ch[i]);
		}

		return answer;
	}
};




class Solution {
public:
    string removeStars(string s) {
        
		std::stack<char> st;

		for(int i = 0; i < s.size(); i++)
		{
			if('*' == s[i] && !st.empty())
			{
				st.pop();
			}
			else
			{
				st.push(s[i]);
			}
		}

		string ret;

		while(!st.empty())
		{
			ret += st.top();
			st.pop();
		}

		reverse(ret.begin(), ret.end());

		return ret;
    }
};

//memory limit
class Solution {
public:
    string removeStars(string s) {
        
		std::stack<char> st;

		for(int i = 0; i < s.size(); i++)
		{
			if('*' == s[i] && !st.empty())
			{
				st.pop();
			}
			else
			{
				st.push(s[i]);
			}
		}

		string ret;

		while(!st.empty())
		{
			ret = st.top() + ret;
			st.pop();
		}

		return ret;
    }
};


//two pointer
class Solution {
public:
	string removeStars(string s) {

		string ch;
		int j = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '*') {
				j--;
			}
			else {
				ch[j++] = s[i];
			}
		}

		string answer = "";
		for (int i = 0; i < j; i++) {
			answer.push_back(ch[i]);
		}

		return answer;
	}
};
