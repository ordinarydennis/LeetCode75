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

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {

		sort(nums.begin(), nums.end(), std::greater<int>());

		auto it = nums.begin();

		while (--k) ++it;

		return *it;
	}
};


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

		priority_queue<int, vector<int>, std::greater<int>> q;

		for (int n : nums)
		{
			q.push(n);

			if (k < q.size()) q.pop();
		}

		return q.top();
	}
};


//heap
//time complexity : n logk
//space comlexity : logn
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {

		priority_queue<int, vector<int>, greater<int>> pq;


		for (int i = 0; i < nums.size(); i++)
		{
			pq.push(nums[i]);
			
			if (k < pq.size())
			{
				pq.pop();
			}

		}

		return pq.top();

	}
};


//sort
//time complexity : NlogN
//space comlexity : logN
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {

		sort(nums.begin(), nums.end(), greater<int>());

		return nums[k - 1];

	}
};





class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {

		sort(nums.begin(), nums.end(), greater<int>());

		return nums[k - 1];
	}
};


class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {

		std::priority_queue<int> q;

		for (int n : nums)
		{
			q.push(n);
		}

		int ret = 0;

		while(k)
		{
			ret = q.top();
			q.pop();
			k--;
		}

		return ret;
	}
};


class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {

		std::priority_queue<int, vector<int>, greater<int>> q;

		for (int n : nums)
		{
			q.push(n);

			if (k < q.size())
			{
				q.pop();
			}
		}

		return q.top();
	}
};