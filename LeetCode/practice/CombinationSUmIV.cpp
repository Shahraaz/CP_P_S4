class Solution
{
public:
	map<int, int> Dp;
	int combinationSum4(vector<int> &nums, int target)
	{
		if (target == 0)
			return 1;
		auto it = Dp.find(target);
		if (it != Dp.end())
			return it->second;
		int &ans = Dp[target];
		for (auto x : nums)
			if (target - x >= 0)
				ans += combinationSum4(nums, target - x);
		return ans;
	}
};