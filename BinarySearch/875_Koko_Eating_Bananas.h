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


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       
		int d = piles.size() / h;

		int p = d * *max_element(piles.begin(), piles.end());

		

		int ret = INT_MAX;

		int total = accumulate(piles.begin(), piles.end(), 0);

		while (1)
		{
			int count = 0;
			int psum = 0;

			for (int n : piles)
			{
				while (0 < n)
				{
					psum += (0 < n - p) ? p : n;

					n -= p;
					
					count++;
				}
			}

			p--;

			ret = min(ret, count);

			if (psum <= total)
			{
				break;
			}
		}

		return ret;
    }
};