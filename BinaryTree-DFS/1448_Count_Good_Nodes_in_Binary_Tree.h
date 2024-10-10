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

	void dfs(TreeNode* node, int max, int& count)
	{
		if (max <= node->val)
		{
			max = node->val;
			count++;
		}
	
		if (node->left)
			dfs(node->left, max, count);

		if (node->right)
			dfs(node->right, max, count);
	}


public:
	int goodNodes(TreeNode* root) {

		int count = 0;

		dfs(root, INT_MIN, count);

		return count;

	}
};



class Solution {


public:
	int goodNodes(TreeNode* root) {


		queue<pair<TreeNode* , TreeNode* >> q;

		q.push( pair<TreeNode*, TreeNode* >{nullptr, root} );

		int count = 0;

		while (!q.empty())
		{
			int sz = q.size();

			for (int i = 0; i < sz; i++)
			{
				auto p = q.front();

				q.pop();

				auto pNode = p.first;
				auto cNode = p.second;

				TreeNode* maxNode = pNode;

				if (nullptr == maxNode || maxNode->val <= cNode->val)
				{
					count++;
					maxNode = cNode;
				}

				if (cNode->left)
				{
					q.push(pair<TreeNode*, TreeNode* >{maxNode, cNode->left});
				}

				if (cNode->right)
				{
					q.push(pair<TreeNode*, TreeNode* >{maxNode, cNode->right});
				}
			}
		}

		return count;

	}
};