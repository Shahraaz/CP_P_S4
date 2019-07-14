class Solution
{
public:
	int climbStairs(int n)
	{
		if (n <= 1)
			return 1;
		vector<int> Dp(2);
		Dp[0] = Dp[1] = 1;
		for (int i = 2; i <= n; ++i)
			Dp[i & 1] += Dp[!(i & 1)];
		return Dp[n & 1];
	}
};