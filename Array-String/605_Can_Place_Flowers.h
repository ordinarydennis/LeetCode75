class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {

		if (0 == n)
		{
			return true;
		}

		for (int i = 0; i < flowerbed.size(); i++)
		{
			if (1 == flowerbed[i])
				continue;

			bool left = true;
			bool right = true;

			if (0 < i && 1 == flowerbed[i - 1])
				left = false;


			if (i + 1 < flowerbed.size() && 1 == flowerbed[i + 1])
				right = false;

			if (left && right)
			{
				flowerbed[i] = 1;
				n--;
				if (0 == n)
				{
					return true;
				}
			}
		}
		return 0 == n;

	}
};


class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {

		if (0 == n)
		{
			return true;
		}

		if (1 == flowerbed.size())
		{
			return 0 == flowerbed[0];
		}


		for (int i = 0; i < flowerbed.size(); i++)
		{
			if (0 == n)
				break;
			
			if (1 == flowerbed[i])
				continue;

			if (0 == i && 0 == flowerbed[i + 1])
			{
				flowerbed[i] = 1;
				n--;
				continue;
			}

			if (i == flowerbed.size() - 1 && 0 == flowerbed[i - 1])
			{
				flowerbed[i] = 1;
				n--;
				continue;
			}

			if (0 < i && 1 == flowerbed[i - 1])
				continue;
			
			if (i < flowerbed.size() - 1 && 1 == flowerbed[i + 1])
				continue;

			flowerbed[i] = 1;
			n--;
		}

		return 0 == n;
	}
};

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {

		for (int i = 0; i < flowerbed.size(); i++)
		{
			if (0 == n) break;

			if (1 == flowerbed[i]) continue;

			if (!(0 <= i - 1 && 1 == flowerbed[i - 1]) && !(i + 1 < flowerbed.size() && 1 == flowerbed[i + 1]))
				flowerbed[i] = 1;

			n -= flowerbed[i];
		}

		return 0 == n;
	}
};


class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int count = 0;
		for (int i = 0; i < flowerbed.size(); i++) {
			// Check if the current plot is empty.
			if (flowerbed[i] == 0) {
				// Check if the left and right plots are empty.
				bool emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);
				bool emptyRightPlot = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);

				// If both plots are empty, we can plant a flower here.
				if (emptyLeftPlot && emptyRightPlot) {
					flowerbed[i] = 1;
					count++;
				}
			}
		}
		return count >= n;
	}
};


class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {

		if (0 == n)
		{
			return true;
		}

		int max = flowerbed.size();

		for (int i = 0 ; i < max; i++)
		{
			if (1 == flowerbed[i])
				continue;


			if (0 <= i - 1 && 1 == flowerbed[i - 1])
			{
				continue;
			}

			if (i < max - 1 && 1 == flowerbed[i + 1])
			{
				continue;
			}

			flowerbed[i] = 1;
			n--;
			
			if (0 == n)
				return true;

		}

		return false;
	}
};
