class Solution {
public:
	int compress(vector<char>& chars) {

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