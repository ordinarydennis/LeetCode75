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
//�ٸ��� or ������ �� -> ��, ���� ��Ʈ�� �߰� ��
//������ 0���� �� -> ������ �ش� ���� ����


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