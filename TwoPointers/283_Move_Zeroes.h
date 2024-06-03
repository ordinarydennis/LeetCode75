class Solution {
public:
	void moveZeroes(vector<int>& nums) {

		int size1 = nums.size();

		nums.erase(
			std::remove(nums.begin(), nums.end(), 0),
			nums.end()
		);

		int size2 = nums.size();

		for (int i = 0; i < size1 - size2; i++)
		{
			nums.push_back(0);
		}
	}
};
