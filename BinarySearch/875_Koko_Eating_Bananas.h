class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {

	}
};

class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {

		int speed = 1;

		while (true)
		{
			long long n = 0;

			for (auto p : piles)
			{
				n += p / speed;
				n += (0 != p % speed) ? 1 : 0;

				if (n > h)
				{
					break;
				}
			}

			if (n <= h)
				return speed;
			else
				speed++;
		}

		return 0;
	}
};

