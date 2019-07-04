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

template <typename T>
void add_self(T &a, T b)
{
	a += b;
	a %= mod;
}

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> can(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> can[i][j];
	vector<int> dp(1 << n);
	dp[0] = 1;
	for (int mask = 0; mask < (1 << n); ++mask)
	{
		int a = __builtin_popcount(mask);
		db(a, mask, 1 << n);
		for (int b = 0; b < n; ++b)
			if (a < n && can[a][b] && !(mask & (1 << b)))
				add_self(dp[mask | (1 << b)], dp[mask]);
	}
	cout << dp[(1 << n) - 1];
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