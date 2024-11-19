class Solution {
public:
	bool increasingTriplet(std::vector<int>& nums) {
		
		int first_num = INT_MAX;
		
		int second_num = INT_MAX;
		
		for (int n : nums) {
			if (n <= first_num) {
				first_num = n;
			}
			else if (n <= second_num) {
				second_num = n;
			}
			else {
				return true;
			}
		}
		return false;
	}
};


class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {

		for (int a = 0; a < nums.size() - 2; a++)
		{
			for (int b = a + 1; b < nums.size() - 1; b++)
			{
				for (int c = b + 1; c < nums.size(); c++)
				{
					if (nums[a] < nums[b] && nums[b] < nums[c])
					{
						return true;
					}
				}
			}
		}

		return false;
	}
};

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {

		vector<pair<int, int>> pList;

		for (int i = 0; i < nums.size(); i++)
		{
			pList.emplace_back(pair<int, int>{ nums[i], i });
		}

		sort(pList.begin(), pList.end(),
			[](const pair<int, int>& l, const pair<int, int>& r) {

				if (l.first == r.first)
					return l.second < r.second;

				return l.first < r.first;
			}
		);

		int max = -1;
		int count = 0;

		for (const auto& p : pList)
		{
			if (max < p.second)
			{
				max = p.second;
				count++;
				if (3 == count)
				{
					break;
				}
			}
		}

		return count == 3;
	}
};

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {

		int first = INT_MAX;
		int second = INT_MAX;

		for (int n : nums)
		{
			if (n <= first)
			{
				first = n;
			}
			else if (n <= second)
			{
				second = n;
			}
			else
			{
				return true;
			}
		}

		return false;
	}
};

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {

		int first = nums[0];
		int second = INT_MIN;

		for (int i = 1; i < nums.size(); i++)
		{
			int n = nums[i];

			if (n < first)
			{
				first = n;
			}
			else if(second < n)
			{
				second = n;
			}
			else if (second < n)
			{
				return true;
			}


		}

		return false;
	}
};


class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {

		int first = nums[0];

		int second = INT_MIN;

		for (int i = 1; i < nums.size(); i++)
		{
			int n = nums[i];

			if (n <= first)
			{
				first = n;
			}
			else if (INT_MIN == second || n < second)
			{
				second = n;
			}
			else if (second < n)
			{
				return true;
			}
		}

		return false;
	}
};
