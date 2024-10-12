/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

	void dfs(TreeNode* root, int sum, int targetSum)
	{
		if (!root)
		{
			return;
		}

		if (targetSum == root->val + sum)
		{
			ret++;
		}

		dfs(root->left, root->val + sum, targetSum);

		dfs(root->right, root->val + sum, targetSum);
	}


	int ret = 0;

public:
	int pathSum(TreeNode* root, int targetSum) {

		dfs(root, 0, targetSum);

		return ret;
	}
};


#include <unordered_map>
#include <vector>

class Solution {
public:
	int subarraySum(std::vector<int>& nums, int k) {
		int count = 0;
		int currSum = 0;
		std::unordered_map<int, int> prefixSumCount;

		for (int num : nums) {
			// Update the current prefix sum
			currSum += num;

			// Situation 1:
			// Continuous subarray starts from the beginning of the array
			if (currSum == k) {
				count++;
			}

			// Situation 2:
			// The number of times the curr_sum − k has occurred already,
			// determines the number of times a subarray with sum k
			// has occurred up to the current index
			if (prefixSumCount.find(currSum - k) != prefixSumCount.end()) {
				count += prefixSumCount[currSum - k];
			}

			// Add the current sum to the map or update existing count
			prefixSumCount[currSum]++;
		}

		return count;
	}
};

#include <unordered_map>

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
	int count = 0;
	long long k;
	std::unordered_map<long long, int> prefixSumCount;

	void preorder(TreeNode* node, long long currSum) {
		if (node == null)
			return;

		// Update the current prefix sum
		currSum += node->val;

		// Check if current prefix sum equals the desired sum
		if (currSum == k)
			count++;

		// Check if there is a prefix sum that up to current node minus k exists
		count += prefixSumCount[currSum - k];

		// Add the current sum into the map to use it for this node's children
		prefixSumCount[currSum]++;

		// Process the left subtree
		preorder(node->left, currSum);

		// Process the right subtree
		preorder(node->right, currSum);

		// After returning from recursion, decrement the count of currSum in the map,
		// as we move back up the tree
		prefixSumCount[currSum]--;
		if (prefixSumCount[currSum] == 0) {
			prefixSumCount.erase(currSum);
		}
	}

public:
	int pathSum(TreeNode* root, int sum) {
		k = sum;
		
		preorder(root, 0);

		return count;
	}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

	void dfs(TreeNode* root, long long sum, int targetSum)
	{
		if (!root)
		{
			return;
		}

		long long curSum = root->val + sum;

		//case 1
		if (curSum == targetSum)
		{
			ret++;
		}

		//case 2
		ret += m[curSum - targetSum];

		m[curSum]++;

		dfs(root->left, curSum, targetSum);

		dfs(root->right, curSum, targetSum);

		m[curSum]--;
	}

	int ret = 0;

	std::unordered_map<long long, int> m;

public:
	int pathSum(TreeNode* root, int targetSum) {
		
		dfs(root, 0, targetSum);

		return ret;
	}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {


	void dfs(TreeNode* node, long long sum, int targetSum)
	{
		if (!node)
			return;

		long long curSum = node->val + sum;

		if (curSum == targetSum)
			ret++;
		
		ret += m[curSum - targetSum];

		m[curSum]++;

		if (node->left)
		{
			dfs(node->left, curSum, targetSum);
		}

		if (node->right)
		{
			dfs(node->right, curSum, targetSum);
		}

		m[curSum]--;

	}

	unordered_map<long long, int> m;

	int ret = 0;

public:
	int pathSum(TreeNode* root, int targetSum) {

		dfs(root, 0, targetSum);

		return ret;
	}
};

//ex) 
// target : 4
// node : 2 -> 2 -> -2 -> 2 -> 2

//hash table
//sum | count
//2 | 1, 2
//4 | 1, 2
//6 | 1

//6 - 4(target) : 2
//2, -2, 2, 2 : 4
//2, 2 : 4
//따라서 마지막 노드 2지점에서 h[6 - 4] -> h[2](h[currSum - k]) 는 2개
//There are two cases: one where the total sum equals the target, 
// and another where the sum of all sub-nodes equals the target


