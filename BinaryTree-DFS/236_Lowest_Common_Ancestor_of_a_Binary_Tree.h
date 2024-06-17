/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {


	bool dfs(TreeNode* root, TreeNode* p)
	{
		if (!root)
		{
			return false;
		}

		if (root->val == p->val)
		{
			m[p->val].push_back(p);
			return true;
		}
		
		bool ret = dfs(root->left, p);
		if (ret)
		{
			m[p->val].push_back(root);
			return true;
		}

		ret = dfs(root->right, p);
		if (ret)
		{
			m[p->val].push_back(root);
			return true;
		}

		return false;
	}

	unordered_map<int, vector<TreeNode*>> m;


public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		dfs(root, p);
		dfs(root, q);

		auto& v1 = m[p->val];
		auto& v2 = m[q->val];


		auto pt = (v1.size() < v2.size()) ?
			pair<vector<TreeNode*>, vector<TreeNode*>>{ v2, v1 } :
			pair<vector<TreeNode*>, vector<TreeNode*>>{ v1, v2 };

		auto target = pt.first;
		auto dest = pt.second;


		for (auto* node : dest)
		{
			auto it = find(target.begin(), target.end(), node);

			if (target.end() != it)
			{
				return *it;
			}
		}

		return nullptr;
	}
};