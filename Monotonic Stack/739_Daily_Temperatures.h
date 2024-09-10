class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {

		stack<pair<int, int>> st;

		vector<int> ret(temperatures.size(), 0);

		for (int i = 0; i < temperatures.size(); i++)
		{
			while(st.size() && st.top().first < temperatures[i])
			{
				ret[st.top().second] = i - st.top().second;
				st.pop();
			}

			st.push({ temperatures[i], i });
		}

		return ret;
	}
};

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {

		stack<pair<int, int>> st;

		vector<int> ret(temperatures.size());

		for (int i = 0; i < temperatures.size(); i++)
		{
			if (0 == st.size())
			{
				st.push({ i, temperatures[i] });
				continue;
			}

			while (st.size())
			{
				auto t = st.top;

				if (t.second < temperatures[i])
				{
					ret[t.first] = i - t.first;
					st.pop();
				}
				else
				{
					break;
				}
			}

			st.push({ i , temperatures[i] });

		}

		return ret;
	}
};