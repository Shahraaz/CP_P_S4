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
vector<int> Edges[nax];
int n, k;

int _n = 1e5 + 10;
vector<ll> Fact(_n), Inv(_n);
int kmod = 1000000007;

ll mul(ll a, ll b)
{
	return a * b % kmod;
}

ll power(int base, int index)
{
	if (index == 0)
		return 1;
	ll temp = power(base, index / 2);
	temp = mul(temp, temp);
	if (index & 1)
		temp = mul(temp, base);
	return temp;
}

void pre()
{
	Fact[0] = 1;
	for (int i = 1; i < _n; ++i)
		Fact[i] = mul(Fact[i - 1], i);
	Inv[_n - 1] = power(Fact[_n - 1], kmod - 2);
	for (int i = _n - 2; i >= 0; --i)
		Inv[i] = mul(Inv[i + 1], (1 + i));
}

ll ncr(int n, int r)
{
	if (n < 0 || r < 0 || n - r < 0)
		return 0;
	return mul(Fact[n], mul(Inv[0], Inv[n - r]));
}

ll solve(int node, int parent, int grand)
{
	ll ways = 1, k1;
	if (parent == 0)
	{
		k1 = k - 1;
	}
	else
	{
		k1 = k - 2;
	}
	if (Edges[node].size() == 0)
		return ways;
	if (parent)
		ways = mul(ways, ncr(k1, (Edges[node].size() - 1)));
	else
		ways = mul(ways, ncr(k1, (Edges[node].size())));
	for (auto child : Edges[node])
	{
		if (child == parent)
			continue;
		auto temp = solve(child, node, parent);
		ways = mul(ways, temp);
	}
	db(k1);
	db(node, ways, ncr(k1, (Edges[node].size() - 1)));
	return ways;
}

void solve()
{
	pre();
	int u, v;
	cin >> n >> k;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> u >> v;
		Edges[u].pb(v);
		Edges[v].pb(u);
	}
	cout << (k * solve(1, 0, 0)) % mod << '\n';
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