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

	TreeNode* dfs(TreeNode* root, int key)
	{
		if (!root)
		{
			return nullptr;
		}

		if (root->val == key)
		{
			auto* n = root->right;

			while (n && n->left)
				n = n->left;

			if (n)
			{
				n->left = root->left;
				return n;
			}
			else
			{
				return root->left;
			}
		}

		if (root->val < key)
			root->right = dfs(root->right, key);
		else
			root->left = dfs(root->left, key);

		return root;
	}

public:
	TreeNode* deleteNode(TreeNode* root, int key) {

		return dfs(root, key);

	}
};