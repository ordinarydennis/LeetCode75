class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {

		sort(nums.begin(), nums.end(), std::greater<int>());

		return nums[k - 1];
	}
};

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {

		priority_queue<int> q;

		for (int n : nums)
		{
			q.push(-n);

			if (k < q.size())
			{
				q.pop();
			}
		}

		return -q.top();
	}
};


class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {

		priority_queue<int> q;

		for (int n : nums)
		{
			q.push(n);
		}

		for (int i = 0; i < k - 1; i++)
		{
			q.pop();
		}
		
		return -q.top();
	}
};