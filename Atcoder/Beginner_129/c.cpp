//Optimise
#include <bits/stdc++.h>
using namespace std;

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

int n, m;
vector<bool> v(2e5);
vector<ll> dp(2e5, -1);

ll ways(int level)
{
	if (level == n)
		return 1;
	if (v[level])
		return 0;
	if (level > n)
		return 0;
	if (dp[level] >= 0)
		return dp[level];
	ll ans = (ways(level + 1) + ways(level + 2)) % mod;
	return dp[level] = ans;
}

void solve()
{
	cin >> n >> m;
	// v.resize(n);
	int x;
	for (int i = 0; i < m; ++i)
	{
		cin >> x;
		v[x] = true;
	}
	cout << ways(0) << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	while (t--)
		solve();
	return 0;
}