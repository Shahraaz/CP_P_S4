//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Online 1
// #define multitest 1
#define Debug 1
typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;
void ControlIO();
void TimerStart();
void TimerStop();
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__)
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
int _n = 200005;
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
	Inv[_n - 1] = power(Fact[_n - 1], mod - 2);
	for (int i = _n - 2; i >= 0; --i)
		Inv[i] = (Inv[i + 1] * (1 + i)) % kmod;
}
void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	pre();
	ll ans = n+m;
	ans = (ans * Fact[n * m - 2]) % mod;
	ans = (ans * Inv[k - 2]) % mod;
	ans = (ans * Inv[n * m - k]) % mod;
	std::cout << ans << '\n';
}

int main()
{
	ControlIO();
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	TimerStart();
	while (t--)
		solve();
	TimerStop();
	return 0;
}

void ControlIO()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef Online
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();

void TimerStart()
{
#ifndef Online
	TimeStart = chrono::steady_clock::now();
#endif
}

void TimerStop()
{
#ifndef Online
	TimeEnd = chrono::steady_clock::now();
	auto ElapsedTime = TimeEnd - TimeStart;
	cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
#endif
}