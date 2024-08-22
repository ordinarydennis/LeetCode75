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
	int pathLength = 0;
	void dfs(TreeNode* node, bool goLeft, int steps) {
		if (node == nullptr) {
			return;
		}
		pathLength = max(pathLength, steps);
		if (goLeft) {
			dfs(node->left, false, steps + 1);
			dfs(node->right, true, 1);
		}
		else {
			dfs(node->left, false, 1);
			dfs(node->right, true, steps + 1);
		}
	}

	int longestZigZag(TreeNode* root) {
		dfs(root->left, false, 1);
		dfs(root->right, true, 1);
		return pathLength;
	}
};

//https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/?envType=study-plan-v2&envId=leetcode-75



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

	bool dfs(TreeNode* root, bool isLeft)
	{
		if (!root)
		{
			return 0;
		}

		int lSize = dfs(root->left, true);

		int rSize = dfs(root->right, false);

		int total = 0;

		if (isLeft)
		{
			total = rSize + 1;
		}
		else
		{
			total = lSize + 1;
		}


		ret = max(ret, total);


		return total;
	}

	int ret = 0;

public:
	int longestZigZag(TreeNode* root) {

		dfs(root->left, true);

		dfs(root->right, false);

		return ret;

	}
};



class Solution {

	void dfs(TreeNode* root, bool fromLeft, int sum)
	{
		if (!root)
		{
			return;
		}
		
		ret = max(ret, sum);

		if (fromLeft)
		{
			dfs(root->left, true, 1);
			dfs(root->right, false, sum + 1);
		}
		else
		{
			dfs(root->right, false, 1);
			dfs(root->left, true, sum + 1);
		}
	}

	int ret = 0;

public:
	int longestZigZag(TreeNode* root) {

		dfs(root->left, true, 1);
		dfs(root->right, false, 1);

		return ret;
	}
};