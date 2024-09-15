class Solution {
public:
	vector<int> countBits(int n) {

		if (0 == n)
		{
			return { 0 };
		}

		vector<int> ret(n + 1, 0);

		ret[0] = 0;
		ret[1] = 1;

		int twoPow = 1;

		int count = 1;

		for (int i = 2; i <=n; i++)
		{
			cout << i << endl;
			if (pow(2, twoPow) == i)
			{
				ret[i] = 1;
				count = 1;
				twoPow++;
			}
			else
			{
				ret[i] = 1 + ret[count];

				count++;
			}

		}

		return ret;
	}
};


class Solution {
public:
	vector<int> countBits(int n) {

		vector<int> ret(n + 1, 0);

		int twoPow = 1;
		int count = 0;

		for (int i = 1; i <= n; i++)
		{
			if (pow(2, twoPow) == i)
			{
				ret[i] = 1;
				count = 1;
				twoPow++;
			}
			else
			{
				ret[i] = 1 + ret[count];
				count++;
			}

		}

		return ret;
	}
};

class Solution {
public:
	vector<int> countBits(int n) {

		vector<int> ret(n + 1, 0); 

		for (int i = 1; i <= n; i++)
		{
			int num = i;

			int c = 0;

			while (num)
			{
				num = num & (num - 1);
				c++;
			}

			ret[i] = c;
		}

		return ret;
	}
};


class Solution {
public:
	vector<int> countBits(int n) {

		if (0 ==n )
		{
			return { 0 };
		}

		int l = 0;
		int p = 1;

		vector<int> ret(n + 1);

		ret[0] = 0;
		ret[1] = 1;


		for (int i = 2; i <= n; i++)
		{
			if (i == pow(2, p))
			{
				p++;
				ret[i] = 1;
				l = i;
			}
			else
			{
				ret[i] = ret[i - l] + 1;
			}
		}


		return ret;
	}
};