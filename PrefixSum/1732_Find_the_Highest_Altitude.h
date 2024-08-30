class Solution {
public:
	int largestAltitude(vector<int>& gain) {

		int a = 0;

		int ret = 0;

		for (int i = 0; i < gain.size(); i++)
		{
			a += gain[i];
			ret = max(ret, a);
		}

		return ret;
	}
};

class Solution {
public:
	int largestAltitude(vector<int>& gain) {

		int sum = 0;

		int ret = 0;

		for (int i = 0; i < gain.size(); i++)
		{
			sum += gain[i];
			ret = max(ret, sum);
		}

		return ret;
	}
};
