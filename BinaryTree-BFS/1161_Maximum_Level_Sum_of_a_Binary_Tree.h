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
//bfs
class Solution {
public:
	int maxLevelSum(TreeNode* root) {

		queue<TreeNode*> q;

		q.push(root);

		int size = q.size();

		int level = 1;

		int minLevel = 1;

		int max = INT_MIN;

		while (size)
		{
			int sum = 0;

			for (int i = 0; i < size; i++)
			{
				auto* n = q.front();

				q.pop();

				sum += n->val;

				if (n->left)
					q.push(n->left);

				if (n->right)
					q.push(n->right);
			}

			if (max < sum)
			{
				max = sum;
				minLevel = level;
			}

			level++;

			size = q.size();
		}

		return minLevel;
	}
};

//dfs
class Solution {

	void dfs(TreeNode* root, int level, vector<int>& sumOfLevel)
	{
		if (!root)
			return;

		if (sumOfLevel.size() == level - 1)
			sumOfLevel.push_back(root->val);
		else
			sumOfLevel[level - 1] += root->val;

		dfs(root->left, level + 1, sumOfLevel);
		dfs(root->right, level + 1, sumOfLevel);
	}

public:

	int maxLevelSum(TreeNode* root) {

		vector<int> sumOfLevel;

		dfs(root, 1, sumOfLevel);

		int max = INT_MIN;

		int ret = 0;

		for (int i = 0; i < sumOfLevel.size(); i++)
		{
			if (max < sumOfLevel[i])
			{
				max = sumOfLevel[i];
				ret = i + 1;
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
	int maxLevelSum(TreeNode* root) {

		queue<TreeNode*> q;

		q.push(root);

		int level = 1;
		int max = INT_MIN;

		int ret = 0;

		while (q.size())
		{
			int s = q.size();

			int sum = 0;

			for (int i = 0; i < s; i++)
			{
				auto* node = q.front();

				q.pop();

				sum += node->val;

				if (node->left)
				{
					q.push(node->left);
				}

				if (node->right)
				{
					q.push(node->right);
				}
			}

			if (max < sum)
			{
				max = sum;
				ret = level;
			}

			level++;
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

	void dfs(TreeNode* node, int level, unordered_map<int, int>& m)
	{
		m[level] += node->val;

		if (node->left)
		{
			dfs(node->left, level + 1, m);
		}

		if (node->right)
		{
			dfs(node->right, level + 1, m);
		}
	}

public:
	int maxLevelSum(TreeNode* root) {

		unordered_map<int, int> m;

		dfs(root, 1, m);

		int max = INT_MIN;

		int ret = INT_MAX;

		for (auto& [level, sum] : m)
		{
			if (sum < max)
				continue;

			if (max < sum)
				max = sum;

			ret = level;
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
	int maxLevelSum(TreeNode* root) {

		queue<TreeNode*> q;

		q.push(root);

		int max = INT_MIN;

		int level = 1;

		int ret = 0;

		while (!q.empty())
		{
			auto sz = q.size();

			int sum = 0;

			for (int i = 0; i < sz; i++)
			{
				auto* node = q.front();

				q.pop();

				sum += node->val;

				if (node->left)
				{
					q.push(node->left);
				}
				if (node->right)
				{
					q.push(node->right);
				}
			}

			if (max < sum)
			{
				max = sum;
				ret = level;
			}

			level++;
		}

		return ret;
	}
};