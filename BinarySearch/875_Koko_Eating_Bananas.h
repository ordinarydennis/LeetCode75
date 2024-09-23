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


//Brute force
class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {

		int eatSize = 1;

		int max = *std::max_element(piles.begin(), piles.end());

while (eatSize <= max)
{
	int total = 0;

	for (int i = 0; i < piles.size(); i++)
	{
		total += (piles[i] / eatSize) + ((piles[i] % eatSize) ? 1 : 0);

		if (h < total) {
			break;
		}
	}

	if (total <= h)
	{
		return eatSize;
	}
	else
	{
		eatSize++;
	}
}

return max;
	}
};


//binary search
class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {

		int min = 1;
		int max = *max_element(piles.begin(), piles.end());;

		int eSize = 0;

		while (min < max)
		{
			eSize = (min + max) / 2;

			int total = 0;

			for (int i = 0; i < piles.size(); i++)
			{
				total += (piles[i] / eSize) + ((piles[i] % eSize != 0) ? 1 : 0);

				if (h < total)
				{
					break;
				}
			}

			//because eSize is valid, need to include eSize
			if (total <= h)
			{
				max = eSize;
			}
			//the case that not satisfy the condtion. do not need to include eSize
			else
			{
				min = eSize + 1;
			}
		}

		return min;
	}
};

/*
max = eSize; vs max = eSize - 1;
max = eSize; 사용하는 이유 :

total <= h 조건을 만족하는 경우, 현재 eSize는 유효한 속도이므로 이 속도 또는 그보다 낮은 속도가 가능한 최적의 속도일 수 있습니다.
따라서 max를 eSize로 설정하여 속도 범위의 상한을 줄입니다.이렇게 하면 min과 max 사이의 범위를 계속 좁혀 나갈 수 있습니다.
이 조건에서 max = eSize - 1로 설정하면, 이미 가능한 솔루션을 제외시키게 됩니다.
왜냐하면 eSize 속도로 정확히 h 시간에 모든 바나나를 먹을 수 있는 상황에서, 그보다 더 낮은 속도는 h 시간 내에 불가능할 수 있기 때문입니다.
min = eSize + 1; 사용하는 이유 :

total > h 조건을 만족하지 않는 경우, 현재의 eSize는 너무 낮아서 시간 h 내에 모든 바나나를 먹을 수 없음을 의미합니다.
따라서 min을 eSize + 1로 설정하여 속도 범위의 하한을 올립니다.
결과적으로, max = eSize; 사용하는 것이 정확한 이유는,
이진 검색을 통해 최소 속도를 찾는 과정에서 가능한 속도 범위를 올바르게 조정하기 위함입니다.max = eSize - 1을 사용하면,
정확한 조건을 충족하는 속도를 제외시키는 실수를 범하게 됩니다.
*/

//brute force
class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {

		int eSize = 1;

		while (true)
		{

			int spendTime = 0;
			for (int i = 0; i < piles.size(); i++)
			{
				spendTime += (piles[i] / eSize) + ((piles[i] % eSize) ? 1 : 0);

				if (h < spendTime)
				{
					break;
				}
			}

			if (h < spendTime)
			{
				eSize++;
			}
			else
			{
				return eSize;
			}
		}

		return 0;
	}
};

class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {

		int minCount = 1;
		int maxCount  = *max_element(piles.begin(), piles.end());

		while (minCount < maxCount)
		{
			int count = 0;

			int eatCount = (minCount + maxCount) / 2;

			for (int i = 0; i < piles.size(); i++)
			{
				int b = piles[i];

				count += b / eatCount + (b % eatCount != 0);

				if (h < count)
					break;
			}

			if (h == count)
			{
				return eatCount;
			}

			//너무 많이 먹은 경우
			if (h < count)
			{
				minCount = eatCount + 1;
			}
			else
			{
				//너무 적게 먹은 경우
				maxCount = eatCount - 1;
			}
		}

		return maxCount;
	}
};