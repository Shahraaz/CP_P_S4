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
	long double ans;
	pair<int, long long> dfs(TreeNode *root)
	{
		if (root == NULL)
		{
			return make_pair(0, 0);
		}
		long long curr = root->val;
		int cnt = 1;
		auto l = dfs(root->left);
		auto r = dfs(root->right);
		curr += l.second + r.second;
		cnt += l.first + r.first;
		ans = max(ans, (long double)curr / cnt);
		return make_pair(cnt, curr);
	}
	double maximumAverageSubtree(TreeNode *root)
	{
		ans = 0;
		dfs(root);
		return ans;
	}
};