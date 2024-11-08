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

class Solution {
public:
	void moveZeroes(vector<int>& nums) {

		vector<int> ret;

		int eCount = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (0 != nums[i])
			{
				ret.push_back(nums[i]);
			}
			else
			{
				eCount++;
			}
		}

		for (int i = 0; i < eCount; i++)
			ret.push_back(0);

		nums = std::move(ret);
	}
};



class Solution {
public:
	void moveZeroes(vector<int>& nums) {

		int point = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (0 != nums[i])
				nums[point++] = nums[i];
		}

		for (int i = point; i < nums.size(); i++)
			nums[i] = 0;
	}
};

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		
		for (int point = 0, i = 0; i < nums.size(); i++)
		{
			if (0 != nums[i])
				std::swap(nums[point++], nums[i]);
		}
	}
};


class Solution {
public:
	void moveZeroes(vector<int>& nums) {

		int z = 0;

		while (z < nums.size() && 0 != nums[z]) z++;

		for(int i = 0; i < nums.size(); i++)
		{
			if (z < i && 0 != nums[i])
			{
				std::swap(nums[z], nums[i]);
				while (0 != nums[z]) z++;
			}
		}
	}
};