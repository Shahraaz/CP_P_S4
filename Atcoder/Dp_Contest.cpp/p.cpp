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
vector<int> Adj[nax];

ll mul(ll a, ll b)
{
	return (a % mod * b % mod) % mod;
}

ll add(ll a, ll b)
{
	return (a + b + mod) % mod;
}

pair<int, int> dfs(int node, int parent)
{
	int all_white = 1;
	int sth_is_black = 0;
	for (int b : Adj[node])
		if (b != parent)
		{
			pair<int, int> p = dfs(b, node);
			int prev = all_white;
			all_white = mul(all_white, p.second);
			sth_is_black = add(mul(prev, p.f), mul(sth_is_black, p.f + p.s));
		}
	return {all_white, add(all_white, sth_is_black)};
}

void solve()
{
	int n, u, v;
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		cin >> u >> v;
		Adj[u].pb(v);
		Adj[v].pb(u);
	}
	auto ret = dfs(1, -1);
	cout << add(ret.f, ret.s);
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