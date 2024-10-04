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
	vector<int> rightSideView(TreeNode* root) {

		if (!root)
			return {};

		std::queue<TreeNode*> q;

		q.push(root);

		std::vector<int> ret;

		int size = q.size();

		while (size)
		{
			for (int i = 0; i < size; i++)
			{
				auto* node = q.front();

				q.pop();

				if (i == 0)
					ret.push_back(node->val);

				if (node->right)
					q.push(node->right);
				if (node->left)
					q.push(node->left);
			}

			size = q.size();
		}

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
	vector<int> rightSideView(TreeNode* root) {

		if (!root)
		{
			return {};
		}

		queue<TreeNode*> q;

		q.push(root);

		vector<int> ret;

		while (q.size())
		{
			int size = q.size();

			for (int i = 0; i < size; i++)
			{
				auto* node = q.front();

				q.pop();

				if (node->left)
				{
					q.push(node->left);
				}

				if (node->right)
				{
					q.push(node->right);
				}

				if (i == size - 1)
				{
					ret.push_back(node->val);
				}
			}
		}

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
	vector<int> rightSideView(TreeNode* root) {

		if (!root)
		{
			return {};
		}

		queue<TreeNode*> q;

		q.push(root);

		vector<int> ret;

		while (!q.empty())
		{
			auto s = q.size();

			int last = 0;

			for (int i = 0; i < s; i++)
			{
				auto* n = q.front();

				q.pop();

				if (n->left)
				{
					q.push(n->left);
				}

				if (n->right)
				{
					q.push(n->right);
				}

				last = n->val;
			}

			ret.push_back(last);

		}

		return ret;
	}
};

class Solution {

	void dfs(int level, TreeNode* node, map<int, vector<int>>& m)
	{
		if (nullptr == node)
		{
			return;
		}

		m[level].push_back(node->val);

		if (node->left)
		{
			dfs(level + 1, node->left, m);
		}

		if (node->right)
		{
			dfs(level + 1, node->right, m);
		}
	}


public:
	vector<int> rightSideView(TreeNode* root) {

		vector<int> ret;

		map<int, vector<int>> m;


		dfs(0, root, m);

		for (auto [_, list] : m)
		{
			ret.push_back(list[list.size() - 1]);
		}

		return ret;
	}
};


class Solution {

	void dfs(int level, TreeNode* node, map<int, int>& m)
	{
		if (nullptr == node)
		{
			return;
		}

		m[level] = node->val;

		if (node->left)
		{
			dfs(level + 1, node->left, m);
		}

		if (node->right)
		{
			dfs(level + 1, node->right, m);
		}
	}


public:
	vector<int> rightSideView(TreeNode* root) {

		vector<int> ret;

		map<int, int> m;

		dfs(0, root, m);

		for (auto [_, last] : m)
		{
			ret.push_back(last);
		}

		return ret;
	}
};