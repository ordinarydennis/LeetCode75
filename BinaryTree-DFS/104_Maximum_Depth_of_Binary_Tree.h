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

	int dfs(TreeNode* root, int h)
	{
		return  (nullptr == root) ? h : std::max(dfs(root->left, h + 1), dfs(root->right, h + 1));
	}


public:
	int maxDepth(TreeNode* root) {

		return dfs(root, 0);

	}
};

