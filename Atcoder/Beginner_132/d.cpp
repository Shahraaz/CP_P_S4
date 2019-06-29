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

ll power(int base, int index)
{
	if (index == 0)
		return 1;
	ll temp = power(base, index / 2);
	temp = (temp * temp) % mod;
	if (index & 1)
		temp = (temp * base) % mod;
	return temp;
}

int n, a, b, c;

int _n = 2000 + 10;
vector<ll> Fact(_n), Inv(_n);
int kmod = 1000000007;

void pre()
{
	Fact[0] = 1;
	for (int i = 1; i < _n; ++i)
		Fact[i] = (Fact[i - 1] * i) % kmod;
	Inv[_n - 1] = power(Fact[_n - 1], kmod - 2);
	for (int i = _n - 2; i >= 0; --i)
		Inv[i] = (Inv[i + 1] * (1 + i)) % kmod;
	// db(Inv[2]*2%mod);
}

ll ncr(int n, int r)
{
	db(n, r);
	if (n < 0 || r < 0 || (n - r < 0))
		return 0;
	return ((Fact[n] * Inv[r]) % mod * Inv[n - r]) % mod;
}

void solve()
{
	pre();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; ++i)
	{
		ll one = ncr(n - k + 1, i);
		ll two = ncr(k - 1, i - 1);
		db(one, two);
		cout << (one * two) % mod << '\n';
	}
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