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