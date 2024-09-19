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

		int end = n;
		int begin = 1;

		int mid = begin + (end - begin) / 2;

		while (begin <= end)
		{
			int result = guess(mid);

			if (0 == result)
				break;
			else if (-1 == result)
				end = mid - 1;
			else
				begin = mid + 1;

			mid = begin + (end - begin) / 2;
		}

		return mid;
	}
};


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

		int left = 1;
		int right= n;

		while (left <= right)
		{
			int mid = left + ((right - left) / 2);

			int result = guess(mid);

			if (0 == result)
				return mid;
			
			if (-1 == result)
				right = mid - 1;
			else
				left = mid + 1;
		}

		return 0;
	}
};