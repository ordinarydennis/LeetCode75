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

	void dfs(TreeNode* root, int pre, int& count)
	{
		if (nullptr == root)
			return;

		if (pre <= root->val)
			count++;

		dfs(root->left, std::max(pre, root->val), count);
		dfs(root->right, std::max(pre, root->val), count);
	}


public:
	int goodNodes(TreeNode* root) {

		int count = 1;

		dfs(root->left, root->val, count);
		dfs(root->right, root->val, count);

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

	void dfs(TreeNode* root, int m)
	{
		if (root->val >= m)
		{
			ret++;
			m = root->val;
		}

		if (root->left)
		{
			dfs(root->left, m);
		}

		if (root->right)
		{
			dfs(root->right, m);
		}
	}

	int ret = 0;

public:
	int goodNodes(TreeNode* root) {

		dfs(root, INT_MIN);

		return ret;

	}
};