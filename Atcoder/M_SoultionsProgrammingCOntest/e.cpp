//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Online 1
#define multitest 1
#define Debug 1
void ControlIO();
void TimerStart();
void TimerStop();
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
const long long mod = 1000003;
mt19937 rang(chrono::steady_clock::now().time_since_epoch().count());
int rng(int lim)
{
	uniform_int_distribution<int> uid(0, lim - 1);
	return uid(rang);
}

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
// cout << fmod((power(d, n+1) * fact(n-1) )%mod * beta((ld)a / d,n),mod) << '\n';

int n, a, b, c;

int _n = 1000003;
vector<ll> Fact(_n), Inv(_n);
int kmod = mod;

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

void solve()
{
	int a, d, n;
	cin >> a >> d >> n;
	if (d == 0)
		cout << power(a, n) << '\n';
	else
	{
		a = (a * power(d, mod - 2)) % mod;
		if (a + n > mod)
			cout << 0 << '\n';
		else
		{
			ll ans = power(d, n);
			ans *= Fact[a + n - 1];
			ans %= mod;
			ans *= Inv[a - 1];
			ans %= mod;
			cout << ans << '\n';
		}
	}
}

int main()
{
	pre();
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