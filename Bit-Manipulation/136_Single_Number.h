class Solution {
public:
	int singleNumber(vector<int>& nums) {

		int result = 0;

		for (int num : nums) {
			result ^= num;
		}

		return result;
	}
};
//다르면 or 연산이 됨 -> 즉, 없는 비트면 추가 됨
//같으면 0으로 됨 -> 같으면 해당 수가 빠짐


class Solution {
public:
	int singleNumber(vector<int>& nums) {

		int ret = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			ret ^= nums[i];
		}

		return ret;

	}
};

class Solution {
public:
	int singleNumber(vector<int>& nums) {

		int ret = 0;

		for (int n : nums)
		{
			ret = ret ^ n;
		}

		return ret;
	}
};

class Solution {
public:
	int singleNumber(vector<int>& nums) {

		unordered_set<int> s;

		for (int n : nums)
		{
			if (s.count(n))
				s.erase(n);
			else
				s.insert(n);
		}

		return *s.begin();
	}
};