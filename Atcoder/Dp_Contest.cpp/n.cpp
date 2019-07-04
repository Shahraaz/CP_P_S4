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

const int nax = 405;
ll INF = 1e18 + 5;
ll dp[nax][nax];

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	auto sum = [&](int L, int R) {
		ll sum = 0;
		for (int i = L; i <= R; ++i)
			sum += a[i];
		return sum;
	};
	for (int l = n - 1; l >= 0; --l)
		for (int r = l; r < n; ++r)
		{
			if (l == r)
				dp[l][r] = 0;
			else
			{
				dp[l][r] = INF;
				ll s = sum(l, r);
				for (int i = l; i <= r - 1; ++i)
					dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r] + s);
			}
		}
	cout << dp[0][n - 1];
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