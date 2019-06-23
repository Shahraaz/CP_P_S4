//Optimise
#include <bits/stdc++.h>
using namespace std;

// #define Online 1
// #define multitest 1
#define Debug 1
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
template <typename Arg1>
void ZZ(const char *name, Arg1 &&arg1)
{
	std::cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char *names, Arg1 &&arg1, Args &&... args)
{
	const char *comma = strchr(names + 1, ',');
	std::cerr.write(names, comma - names) << " = " << arg1;
	ZZ(comma, args...);
}
#else
#define db(...)
#endif

typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;

class OrderlyString
{
private:
	/* data */
public:
	int longestLength(string s)
	{
		int n = s.length();
		vector<vector<int>> Dp(n, vector<int>(26));
		Dp[0][s[0] - 'A'] = 1;
		int maxi = 1;
		for (int i = 1; i < n; ++i)
		{
			int cur = s[i] - 'A';
			for (int j = 0; j < 26; ++j)
			{
				if (j <= cur)
					Dp[i][curr] = max(Dp[i][curr], Dp[i - 1][j] + 1);
				else
					Dp[i][curr] = max(Dp[i][curr], Dp[i - 1][j]);
				Dp[i][j] = max(Dp[i][j], Dp[i - 1][j]);
				maxi = max(maxi, Dp[i][curr]);
			}
		}
		return maxi;
	}
};

#ifndef Online
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	OrderlyString S;
	while (t--)
		cout << S.longestLength("GFEDCBA");
	return 0;
}
#endif