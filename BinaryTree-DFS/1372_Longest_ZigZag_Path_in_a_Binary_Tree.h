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

	int ret = 0;

	pair<int, bool> dfs(TreeNode* root, bool isLeft)
	{
		if (!root)
		{
			return { 0 , false };
		}


		auto lp = dfs(root->left, true);
		auto rp = dfs(root->right, false);

		if (isLeft)
		{
			ret = max(ret, rp.first + 1);

			return { rp.first + 1, false };
		}
		else
		{
			ret = max(ret, lp.first + 1);

			return { lp.first + 1, true };
		}
	}


public:
	int longestZigZag(TreeNode* root) {

		dfs(root->left, true);
		dfs(root->right, true);

		return ret;
	}
};