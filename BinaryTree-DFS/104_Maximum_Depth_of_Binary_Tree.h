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

	void dfs(TreeNode* root, int d)
	{
		if (!root)
			return;

		if (!root->left && !root->right)
			ret = max(ret, d);

		if (root->left)
			dfs(root->left, d + 1);

		if (root->right)
			dfs(root->right, d + 1);
	}


	int ret = 0;


public:
	int maxDepth(TreeNode* root) {

		dfs(root, 1);

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

	int dfs(TreeNode* root, int d)
	{
		return (nullptr != root) ?
			max(
				dfs(root->left, d + 1), 
				dfs(root->right, d + 1)
				):
				d;
			
	}


public:
	int maxDepth(TreeNode* root) {
		
		return dfs(root, 0);

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

	int dfs(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}

		return std::max(
			dfs(root->left) + 1,
			dfs(root->right) + 1
		);
	}


public:
	int maxDepth(TreeNode* root) {

		return dfs(root);

	}
};