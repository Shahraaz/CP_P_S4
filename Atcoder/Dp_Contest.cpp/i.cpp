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
	int n;
	cin >> n;
	vector<ld> Dp(n + 1);
	ld x;
	Dp[0] = 1;
	db("start");
	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		for (int j = i; j >= 0; --j)
		{
			db(j);
			Dp[j] = Dp[j] * (1 - x) + (j == 0 ? 0 : (Dp[j - 1] * x));
		}
	}
	db("here");
	ld ans = 0;
	for (int i = 0; i <= n; ++i)
	{
		int j = n - i;
		if (i > j)
			ans += Dp[i];
	}
	cout << fixed << setprecision(10);
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