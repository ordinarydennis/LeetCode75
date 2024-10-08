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

	void dfs(TreeNode* root, vector<int>& v)
	{
		if (!root->left && !root->right)
		{
			v.push_back(root->val);
			return;
		}

		if (root->left)
			dfs(root->left, v);

		if (root->right)
			dfs(root->right, v);
	}


public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {

		vector<int> v1;
		vector<int> v2;

		dfs(root1, v1);
		dfs(root2, v2);

		return v1 == v2;
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

	void dfs(TreeNode* node, vector<int>& v)
	{
		if(!node->left && !node->right)
		{
			v.push_back(node->val);
			return;
		}

		if(node->left)
		{
			dfs(node->left, v);
		}

		if (node->right)
		{
			dfs(node->right, v);
		}
	}


public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {

		vector<int> v1, v2;

		dfs(root1, v1);
		dfs(root2, v2);
		
		return v1 == v2;

	}
};