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