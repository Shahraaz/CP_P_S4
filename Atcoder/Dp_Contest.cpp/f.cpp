//Optimise
#include <bits/stdc++.h>
using namespace std;

// #define multitest 1
// #define Debug 1
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

void solve()
{
	string s, t;
	cin >> s >> t;
	int n = s.length();
	int m = t.length();
	s = '$' + s;
	t = '$' + t;
	vector<vector<int>> Dp(n + 1, vector<int>(m + 1));
	vector<vector<int>> Pad(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			if (s[i] == t[j])
			{
				Dp[i][j] = 1 + Dp[i - 1][j - 1];
				Pad[i][j] = 1;
			}
			else if (Dp[i - 1][j] < Dp[i][j - 1])
			{
				Dp[i][j] = Dp[i][j - 1];
				Pad[i][j] = 2;
			}
			else
			{
				Dp[i][j] = Dp[i - 1][j];
				Pad[i][j] = 3;
			}
		}
	int i = n, j = m;
	string ans = "";
	while (i > 0 && j > 0)
	{
		db(i, j);
		switch (Pad[i][j])
		{
		case 1:
			ans += s[i];
			i--;
			j--;
			break;

		case 2:
			j--;
			break;

		case 3:
			i--;
			break;

		default:
			break;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}

int main()
{
#ifndef Debug
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#endif
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	while (t--)
		solve();
	return 0;
}