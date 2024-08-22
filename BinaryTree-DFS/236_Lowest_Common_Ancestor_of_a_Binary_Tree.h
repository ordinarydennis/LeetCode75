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

class Solution {

	private TreeNode ans;

	public Solution() {
		// Variable to store LCA node.
		this.ans = null;
	}

	private boolean recurseTree(TreeNode currentNode, TreeNode p, TreeNode q) {

		// If reached the end of a branch, return false.
		if (currentNode == null) {
			return false;
		}

		// Left Recursion. If left recursion returns true, set left = 1 else 0
		int left = this.recurseTree(currentNode.left, p, q) ? 1 : 0;

		// Right Recursion
		int right = this.recurseTree(currentNode.right, p, q) ? 1 : 0;

		// If the current node is one of p or q
		int mid = (currentNode == p || currentNode == q) ? 1 : 0;


		// If any two of the flags left, right or mid become True
		if (mid + left + right >= 2) {
			this.ans = currentNode;
		}

		// Return true if any one of the three bool values is True.
		return (mid + left + right > 0);
	}

	public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
		// Traverse the tree
		this.recurseTree(root, p, q);
		return this.ans;
	}
}

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

	int dfs(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (!root)
		{
			return false;
		}

		if (ret)
		{
			return false;
		}

		int left = dfs(root->left, p, q) ? 1 : 0;
		int right = dfs(root->right, p, q) ? 1 : 0;
		int mid = (root == p) || (root == q) ? 1 : 0;

		if (left + right + mid >= 2)
		{
			ret = root;
		}

		return left + right + mid > 0;

	}
	
	TreeNode* ret = nullptr;

public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		dfs(root, p, q);

		return ret;
	}
};


https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/editorial/?envType=study-plan-v2&envId=leetcode-75



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

	bool dfs(TreeNode* root, int val, vector<TreeNode*>& v)
	{
		if (!root)
		{
			return false;
		}

		if (root->val == val)
		{
			v.push_back(root);
			return true;
		}

		bool lFind = dfs(root->left, val, v);
		bool rFind = dfs(root->right, val, v);

		if (lFind || rFind)
		{
			v.push_back(root);
			return true;
		}
		else
		{
			return false;
		}
	}


public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		vector<TreeNode*> v1;
		vector<TreeNode*> v2;

		dfs(root, p->val, v1);
		dfs(root, q->val, v2);

		for (auto n1 : v1)
		{
			for (auto n2 : v2)
			{
				if (n1->val == n2->val)
				{
					return n1;
				}
			}
		}

		return nullptr;
	}
};