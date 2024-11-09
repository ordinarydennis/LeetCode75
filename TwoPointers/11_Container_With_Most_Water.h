class Solution {
public:
	int maxArea(vector<int>& height) {

		int left = 0;
		int right = height.size() - 1;

		int ret = 0;

		while (left < right)
		{
			int minH = std::min(height[left], height[right]);

			ret = max(ret, minH * (right - left));

			(height[left] < height[right]) ? ++left : --right;
		}

		return ret;

	}
};


class Solution {
public:
	int maxArea(vector<int>& height) {

		int left = 0;

		int right = height.size() - 1;

		int ret = 0;

		while (left < right)
		{
			int h = height[left] < height[right] ? height[left] : height[right];
			
			ret = max(ret, h * (right - left));

			if (height[left] < height[right])
				left++;				
			else
				right--;
		}
		
		return ret;
	}
};

class Solution {
public:
	int maxArea(vector<int>& height) {

		int left = 0;
		int right = height.size() - 1;

		int ret = 0;

		while(left < right)
		{
			int amount = (right - left) * min(height[left], height[right]);

			ret = max(ret, amount);

			if (height[left] < height[right])
			{
				left++;
			}
			else
			{
				right--;
			}
		}

		return ret;
	}
};