/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {


public:
	int guessNumber(int n) {
		
		int s = 1;
		int e = n;

		while (s <= e)
		{
			int m = s + (e - s) / 2;

			int g = guess(m);

			if (0 == guess(m))
				return m;

			if (g < 0)
				e = m;
			else
				s = m + 1;
		}

		return -1;
	}
};