class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {

		std::stack<int> st;

		int sign = 0;

		for (int i = 0; i < asteroids.size(); i++)
		{
			if (st.empty())
			{
				st.push(asteroids[i]);
				sign = 0 < asteroids[i] ? 1 : -1;
			}

			int targetSing = 0 < asteroids[i] ? 1 : -1;

			if (sign == targetSing)
			{
				st.push(asteroids[i]);
			}
			else
			{
				if (1 == targetSing || -1 == sign)
				{
					st.push(asteroids[i]);
					sign = targetSing;
				}
				else
				{
					while (st.size())
					{
						auto t = st.top();

						sign = 0 < st.top() ? 1 : -1;

						if (abs(t) <= abs(asteroids[i]))
						{
							st.pop();
						}
						else
						{
							break;
						}
					}
				}

			}
		}

		vector<int> ret;

		while (st.size())
		{
			ret.push_back(st.top());
			st.pop();
		}

		std::reverse(ret.begin(), ret.end());

		return ret;
	}
};