class Solution {
public:
	int minFlips(int a, int b, int c) {

		int t = a | b;

		int ret = 0;

		for (int i = 0; i < 32; i++)
		{
			int t2 = t & 1;
			int c2 = c & 1;

			if (t2 != c2)
			{
				if (c2 == 1)
				{
					ret++;
				}
				//c2 == 0
				else
				{
					if (a & 1)
						ret++;

					if (b & 1)
						ret++;
				}
			}

			a = a >> 1;
			b = b >> 1;
			t = t >> 1;
			c = c >> 1;
		}

		return ret;

	}
};