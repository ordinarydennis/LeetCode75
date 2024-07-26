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