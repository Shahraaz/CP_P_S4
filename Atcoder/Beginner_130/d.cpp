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

void solve()
{
	ll n, k;
	cin >> n >> k;
	// db(k);
	vector<ll> A(n);
	for (auto &x : A)
		cin >> x;
	vector<ll> Sum(n);
	Sum[0] = A[0];
	for (int i = 1; i < n; ++i)
		Sum[i] = Sum[i - 1] + A[i];
	ll answer = 0;
	for (int i = 0; i < n; ++i)
	{
		ll up = Sum.end() - lower_bound(Sum.begin(), Sum.end(), ((i == 0) ? 0 : Sum[i - 1]) + k);
		// db(up, Sum[i] + k);
		answer += up;
	}
	cout << answer;
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