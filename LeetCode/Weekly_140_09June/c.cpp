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
public:
	pair<TreeNode *, long long> sufficientSubset(TreeNode *root, long long limit, long long roottohere)
	{
		if (root == nullptr)
			return {nullptr, 0};
		auto left = sufficientSubset(root->left, limit - root->val, roottohere);
		auto right = sufficientSubset(root->right, limit - root->val, roottohere);
		root->left = left.first;
		root->right = right.first;
		long long leafpath = root->val + max(left.second, right.second);
		if (leafpath >= limit)
			return {root, leafpath};
		return {nullptr, leafpath};
	}
	TreeNode *sufficientSubset(TreeNode *root, int limit)
	{
		return sufficientSubset(root, limit, 0).first;
	}
};