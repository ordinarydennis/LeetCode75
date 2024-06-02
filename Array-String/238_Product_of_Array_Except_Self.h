class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {

		int size = nums.size();

		vector<int> llist(size);
		vector<int> rlist(size);

		llist[0] = 1;
		for (int i = 1; i < size; i++)
		{
			llist[i] = nums[i - 1] * llist[i - 1];
		}

		rlist[size - 1] = 1;
		for (int i = size - 2; 0 <= i; i--)
		{
			rlist[i] = nums[i + 1] * rlist[i + 1];
		}

		vector<int> ret(size);

		for (int i = 0; i < size; i++)
		{
			ret[i] = llist[i] * rlist[i];
		}

		return ret;
	}
};

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {

		unordered_set<int> zero;

		int total = 1;

		for (int i = 0; i < nums.size(); i++)
		{
			if (0 != nums[i])
			{
				total *= nums[i];
			}
			else
			{
				zero.insert(i);
			}
		}
		
		vector<int> ret(nums.size());

		if (1 < zero.size())
		{
			return ret;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (zero.size() == 0)
			{
				if (zero.count(i))
				{
					ret[i] = total;
				}
				else
				{
					ret[i] = total / nums[i];
				}
			}
			else
			{
				if (zero.count(i))
				{
					ret[i] = total;
				}
				else
				{
					ret[i] = 0;
				}
			}
		}

		return ret;
	}
};

//if the size of nums is n, 
//time complexity O(n)
//space complexity O(n)


class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		// The length of the input array
		int length = nums.size();

		// The left and right arrays as described in the algorithm
		vector<int> L(length), R(length), answer(length);

		// L[i] contains the product of all the elements to the left
		// Note: for the element at index '0', there are no elements to the
		// left, so the L[0] would be 1
		L[0] = 1;
		for (int i = 1; i < length; i++) {
			// L[i - 1] already contains the product of elements to the left of
			// 'i - 1' Simply multiplying it with nums[i - 1] would give the
			// product of all elements to the left of index 'i'
			L[i] = nums[i - 1] * L[i - 1];
		}

		// R[i] contains the product of all the elements to the right
		// Note: for the element at index 'length - 1', there are no elements to
		// the right, so the R[length - 1] would be 1
		R[length - 1] = 1;
		for (int i = length - 2; i >= 0; i--) {
			// R[i + 1] already contains the product of elements to the right of
			// 'i + 1' Simply multiplying it with nums[i + 1] would give the
			// product of all elements to the right of index 'i'
			R[i] = nums[i + 1] * R[i + 1];
		}

		// Constructing the answer array
		for (int i = 0; i < length; i++) {
			// For the first element, R[i] would be product except self
			// For the last element of the array, product except self would be
			// L[i] Else, multiple product of all elements to the left and to
			// the right
			answer[i] = L[i] * R[i];
		}

		return answer;
	}
};

https://leetcode.com/problems/product-of-array-except-self/editorial/?envType=study-plan-v2&envId=leetcode-75
