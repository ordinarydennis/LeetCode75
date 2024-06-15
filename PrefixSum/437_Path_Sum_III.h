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

	unordered_map<uint64_t, int> memo;
	int t;

	void dfs(TreeNode* root, uint64_t curSum, int& count)
	{
		if (nullptr == root)
			return;

		uint64_t sum = root->val + curSum;

		if (sum == t)
			count++;

		if (memo.count(sum - t))
			count += memo[sum - t];

		memo[sum]++;

		dfs(root->left, sum, count);
		dfs(root->right, sum, count);

		memo[sum]--;

		return;
	}


public:
	int pathSum(TreeNode* root, int targetSum) {

		t = targetSum;

		int ret = 0;

		dfs(root, 0, ret);

		return ret;
	}
};