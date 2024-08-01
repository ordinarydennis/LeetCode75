class Solution {

	void dfs(int index, string& digits, unordered_map<int, string>& m, string& out)
	{
		if (index == digits.size())
		{
			ret.push_back(out);
			return;
		}

		char c = digits[index];

		int n = c - '0';

		for (char c : m[n])
		{
			out.push_back(c);

			dfs(index + 1, digits, m, out);

			out.pop_back();
		}
	}

private:
	vector<string> ret;

public:
	vector<string> letterCombinations(string digits) {

		if (digits.empty())
		{
			return {};
		}

		unordered_map<int, string> m = {
			{2, "abc"},
			{3, "def"},
			{4, "ghi"},
			{5, "jkl"},
			{6, "mno"},
			{7, "pqrs"},
			{8, "tuv"},
			{9, "wxyz"},
		};

		string s;

		dfs(0, digits, m, s);

		return ret;

	}
};



class Solution {

	void dfs(vector<vector<char>>& phone, string& digits, int index, string& result)
	{
		if (digits.size() <= index)
		{
			ret.push_back(result);
			return;
		}

		auto list = phone[digits[index] - '0'];

		for (int i = 0; i < list.size(); i++)
		{
			result.push_back(list[i]);

			dfs(phone, digits, index + 1, result);

			result.pop_back();
		}
	}

	vector<string> ret;

public:
	vector<string> letterCombinations(string digits) {

		if (0 == digits.size())
		{
			return {};
		}

		vector<vector<char>> phone = {
			{' '},
			{' '},
			{'a', 'b', 'c'},
			{'d', 'e', 'f'},
			{'g', 'h', 'i'},
			{'j', 'k', 'l'},
			{'m', 'n', 'o'},
			{'p', 'q', 'r', 's'},
			{'t', 'u', 'v'},
			{'w', 'x', 'y','z'},
		};

		string result;

		dfs(phone, digits, 0, result);

		return ret;
	}
};
