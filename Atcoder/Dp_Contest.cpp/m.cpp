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

const int nax = 1e5 + 10;
ll dp[nax];

template <typename T>
void add_self(T &a, T b)
{
	a += b;
	a += mod;
	a %= mod;
}

void solve()
{
	int n, k, x;
	cin >> n >> k;
	dp[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		vector<ll> fake(k + 1);
		for (int used = k; used >= 0; --used)
		{
			ll temp = dp[used];
			int l = used + 1;
			int r = used + min(x, k - used);
			if (l <= r)
			{
				add_self(fake[l], temp);
				if (r + 1 <= k)
					add_self(fake[r + 1], -temp);
			}
		}
		ll sum = 0;
		db("here",k);
		for (int i = 0; i <= k; ++i)
		{
			db("Hi");
			add_self(sum, fake[i]);
			add_self(dp[i], sum);
			db(dp[i], i);
		}
	}
	cout << dp[k];
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