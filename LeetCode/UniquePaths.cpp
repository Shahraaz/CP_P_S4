class Solution
{
public:
	int ncr(int n, int r)
	{
		if (n == 0 || r == 0)
			return 1;
		if (n - r < r)
			r = n - r;
		vector<long long> Dp(n + 1);
		for (int i = 0; i <= n; ++i)
			for (int j = r; j >= 0; --j)
			{
				if (j == 0)
					Dp[j] = 1;
				else
					Dp[j] += Dp[j - 1];
				//cout << i << ' ' << j << ' ' << Dp[j] << '\n';
			}
		return Dp[r];
	}
	int uniquePaths(int m, int n)
	{
		return ncr(m + n - 2, m - 1);
	}
};