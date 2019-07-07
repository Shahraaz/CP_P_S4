/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
	set<int> Del;
	vector<TreeNode *> res;
	TreeNode *fun(TreeNode *root, bool delroot)
	{
		vector<TreeNode *> res;
		if (root == NULL)
			return NULL;
		cout << root->val << ' ' << delroot << '\n';
		if (Del.count(root->val))
		{
			fun(root->left, 1);
			fun(root->right, 1);
			return NULL;
		}
		if (delroot)
			res.push_back(root);
		root->left = fun(root->left, 0);
		root->right = fun(root->right, 0);
		return root;
	}

public:
	vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
	{
		vector<TreeNode *> res;
		if (root == NULL)
			return res;
		for (int x : to_delete)
			Del.insert(x);
		fun(root, 1);
		return res;
	}
};