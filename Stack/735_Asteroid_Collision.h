class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {

		std::stack<int> st;

		for (int i = 0; i < asteroids.size(); i++)
		{
			bool isExplode = false;

			while (st.size() && 0 < st.top() && 0 > asteroids[i])
			{
				if (abs(st.top()) < abs(asteroids[i]))
				{
					st.pop();
					continue;
				}

				if (abs(st.top()) == abs(asteroids[i]))
				{
					st.pop();
				}

				isExplode = true;
				break;
			}

			if (false == isExplode)
			{
				st.push(asteroids[i]);
			}
		}

		vector<int> ret;
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

//https://leetcode.com/problems/asteroid-collision/editorial/?envType=study-plan-v2&envId=leetcode-75
class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		stack<int> st;

		for (int asteroid : asteroids) {
			int flag = 1;
			while (!st.empty() && (st.top() > 0 && asteroid < 0)) {
				// If the top asteroid in the stack is smaller, then it will explode.
				// Hence pop it from the stack, also continue with the next asteroid in the stack.
				if (abs(st.top()) < abs(asteroid)) {
					st.pop();
					continue;
				}
				// If both asteroids are the same size, then both asteroids will explode.
				// Pop the asteroid from the stack; also, we won't push the current asteroid to the stack.
				else if (abs(st.top()) == abs(asteroid)) {
					st.pop();
				}

				// If we reach here, the current asteroid will be destroyed
				// Hence, we should not add it to the stack
				flag = 0;
				break;
			}

			if (flag) {
				st.push(asteroid);
			}
		}

		// Add the asteroids from the stack to the vector in the reverse order.
		vector<int> remainingAsteroids(st.size());
		for (int i = remainingAsteroids.size() - 1; i >= 0; i--) {
			remainingAsteroids[i] = st.top();
			st.pop();
		}

		return remainingAsteroids;
	}
};