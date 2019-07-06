//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Online 1
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

int _n = 1e6 + 10;
vector<ll> Fact(_n), Inv(_n);
int kmod = 1000000007;

ll power(ll base, int index)
{
	if (index == 0)
		return 1;
	ll temp = power(base, index / 2);
	temp *= temp;
	temp %= mod;
	if (index & 1)
		temp *= base;
	return temp % mod;
}
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
	if (n < 0 || r < 0 || n < r)
		return 0;
	return ((Fact[n] * Inv[r]) % mod * Inv[n - r]) % mod;
}

class FamilySeatingArrangement
{
private:
	void add_self(ll &a, ll b)
	{
		a += b;
		if (a >= mod)
			a -= mod;
	}

public:
	int countWays(vector<int> a, int k)
	{
		db(k);
		pre();
		ll res = 0;
		int cnt = 0, n = a.size();
		for (int i = 0; i < n; ++i)
			cnt += a[i];
		for (int i = 1; i <= min(n, k); ++i)
		{
			ll t1 = ncr(k, i), t2 = ncr(n - 1, i - 1), t3 = Fact[i], t4 = power(k - i + 1, cnt);
			db("kck1", t1);
			db("n_1ck_1", t2);
			db("Factk1", t3);
			db("index", t4);
			ll temp = (t1 * t2) % mod;
			temp = (temp * t3) % mod;
			temp = (temp * t4) % mod;
			db(temp, i);
			db("-------------------");
			add_self(res, temp);
		}
		return res;
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
	FamilySeatingArrangement S;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &x:a)
			cin >> x;
		cin >> n;
		cout << S.countWays(a,n) << '\n';
	}
	return 0;
}
#endif