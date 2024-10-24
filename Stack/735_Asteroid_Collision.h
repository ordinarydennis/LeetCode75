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


class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {

		stack<int> st;

		for (int i = 0; i < asteroids.size(); i++)
		{
			auto a = asteroids[i];

			if (st.empty())
			{
				st.push(a);
				continue;
			}

			while (st.size())
			{
				auto t = st.top();

				//meet
				if (0 < t && a < 0)
				{
					if(t > -1 * a)
					{ 
						break;
					}
					else if (t < -1 * a)
					{
						st.pop();

						if (st.empty())
						{
							st.push(a);
							break;
						}
					}
					else if (t == -1 * a)
					{
						st.pop();
						break;
					}
				}
				else
				{
					st.push(a);
					break;
				}
			}

		}


		//vector<int> ret;

		/*while (st.size())
		{
			ret.push_back(st.top());
			st.pop();
		}

		reverse(ret.begin(), ret.end());*/


		vector<int> ret(st.size());

		for (int i = ret.size() - 1; 0 <= i; i--)
		{
			ret[i] = st.top();
			st.pop();
		}

		return ret;
	}
};

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


class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {

		stack<int> st;

		for (int i = 0; i < asteroids.size(); i++)
		{
			//비어있으면 넣는다.
			if (st.empty())
			{
				st.push(asteroids[i]);
				continue;
			}

			//다른 부호라면
			while (!st.empty())
			{
				//같은 부호인지 본다.
				if (0 < st.top() && 0 < asteroids[i] || 0 > st.top() && 0 > asteroids[i])
				{
					st.push(asteroids[i]);
					break;
				}

				if (0 > st.top() && 0 < asteroids[i])
				{
					st.push(asteroids[i]);
					break;
				}

				int n = abs(asteroids[i]);
				int stn = abs(st.top());

				if (n > stn)
				{
					st.pop();
					if (st.empty())
					{
						st.push(asteroids[i]);
						break;
					}
				}
				else if (n == stn)
				{
					st.pop();
					break;
				}
				else
				{
					break;
				}
			}
		}


		vector<int> ret;
		
		while(!st.empty())
		{ 
			ret.push_back(st.top());	
			st.pop();
		}

		reverse(ret.begin(), ret.end());

		return ret;
	}
};