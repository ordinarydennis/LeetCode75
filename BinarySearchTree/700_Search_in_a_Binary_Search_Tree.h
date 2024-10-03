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

	
	void dfs(TreeNode* root, int val)
	{
		if (nullptr != ret)
			return;

		if (nullptr == root)
			return;

		if (root->val == val)
		{
			ret = root;
			return;
		}

		(root->val < val) ? dfs(root->right, val) : dfs(root->left, val);
	}

	TreeNode* ret = nullptr;

public:
	TreeNode* searchBST(TreeNode* root, int val) {

		dfs(root, val);

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

public:
	TreeNode* searchBST(TreeNode* root, int val) {

		if (nullptr == root)
			return nullptr;


		if(root->val == val)
			return root;

		return (root->val < val) ? searchBST(root->right, val) : searchBST(root->left, val);

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
public:
	TreeNode* searchBST(TreeNode* root, int val) {

		while (root && root->val != val)
		{
			root = (root->val < val) ? root->right : root->left;
		}

		return root;
	}
};