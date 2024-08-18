class Solution {
public:
	/*
	One step right and then always left
	*/
	int successor(TreeNode* root) {
		root = root->right;
		while (root->left != nullptr) root = root->left;
		return root->val;
	}

	/*
	One step left and then always right
	*/
	int predecessor(TreeNode* root) {
		root = root->left;
		while (root->right != nullptr) root = root->right;
		return root->val;
	}

	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr) return nullptr;

		// delete from the right subtree
		if (key > root->val) {
			root->right = deleteNode(root->right, key);
		}
		// delete from the left subtree
		else if (key < root->val) {
			root->left = deleteNode(root->left, key);
		}
		// delete the current node
		else {
			// the node is a leaf
			if (root->left == nullptr && root->right == nullptr) {
				root = nullptr;
			}
			// the node is not a leaf and has a right child
			else if (root->right != nullptr) {
				root->val = successor(root);
				root->right = deleteNode(root->right, root->val);
			}
			// the node is not a leaf, has no right child, and has a left child    
			else {
				root->val = predecessor(root);
				root->left = deleteNode(root->left, root->val);
			}
		}
		return root;
	}
};

https://leetcode.com/problems/delete-node-in-a-bst/?envType=study-plan-v2&envId=leetcode-75


//solved again, 15m
class Solution {

	int GetNext(TreeNode* root)
	{
		auto* node = root->right;

		while (node->left)
			node = node->left;

		return node->val;
	}

	int GetPre(TreeNode* root)
	{
		auto* node = root->left;

		while (node->right)
			node = node->right;

		return node->val;
	}

	TreeNode* dfs(TreeNode* root, int key)
	{
		if (!root)
			return nullptr;

		if (root->val == key)
		{
			if (root->right)
			{
				root->val = GetNext(root);
				root->right = dfs(root->right, root->val);
			}
			else if (root->left)
			{
				root->val = GetPre(root);
				root->left = dfs(root->left, root->val);
			}
			else
			{
				root = nullptr;
			}
		}
		else
		{
			if (root->val < key)
			{
				root->right = dfs(root->right, key);
			}
			else if (key < root->val)
			{
				root->left = dfs(root->left, key);
			}
		}

		return root;
	}

public:
	TreeNode* deleteNode(TreeNode* root, int key) {

		return dfs(root, key);

	}
};



class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	/*
	One step right and then always left
	*/
	int successor(TreeNode* root) {
		root = root->right;
		while (root->left != nullptr) root = root->left;
		return root->val;
	}

	/*
	One step left and then always right
	*/
	int predecessor(TreeNode* root) {
		root = root->left;
		while (root->right != nullptr) root = root->right;
		return root->val;
	}

	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr) return nullptr;

		// delete from the right subtree
		if (key > root->val) 
			root->right = deleteNode(root->right, key);
		// delete from the left subtree
		else if (key < root->val) 
			root->left = deleteNode(root->left, key);
		// delete the current node
		else 
		{
			// the node is a leaf
			if (root->left == nullptr && root->right == nullptr) {
				delete root;
				root = nullptr;
			}
			// the node is not a leaf and has a right child
			else if (root->right != nullptr) {
				root->val = successor(root);
				root->right = deleteNode(root->right, root->val);
			}
			// the node is not a leaf, has no right child, and has a left child    
			else {
				root->val = predecessor(root);
				root->left = deleteNode(root->left, root->val);
			}
		}
		return root;
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
	TreeNode* deleteNode(TreeNode* root, int key) {

		if (!root)
		{
			return nullptr;
		}

		if (root->val == key)
		{
			if (nullptr == root->left && nullptr == root->right)
			{
				delete root;
				return nullptr;
			}
			else if (root->right)
			{
				auto r = root->right;

				while (r->left)
					r = r->left;

				root->val = r->val;

				root->right = deleteNode(root->right, r->val);
			}

			else if (root->left)
			{
				auto l = root->left;
				
				while (l->right)
					l = l->right;

				root->val = l->val;

				root->left = deleteNode(root->left, l->val);
			}
		}
		else
		{
			if (root->val < key)
				root->right = deleteNode(root->right, key);
			else
				root->left = deleteNode(root->left, key);		
		}

		return root;
	}
};