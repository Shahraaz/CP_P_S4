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

vector<ll> a;
ll getArr(int n, ll initial)
{
	for (int i = 0; i < n - 1; ++i)
		initial = a[i] - initial;
	return initial;
}

void brute(int low, int high, int n)
{
	for (int i = low; i <= high; ++i)
	{
		ll expected1 = a[n - 1] - i;
		ll received1 = getArr(n, i);
		if (expected1 == received1)
		{
			cout << i << ' ';
			for (int j = 0; j < n - 1; ++j)
			{
				i = a[j] - i;
				cout << i << ' ';
			}
			return;
		}
	}
}

void solve()
{
	int n;
	cin >> n;
	a.resize(n);
	for (ll &x : a)
	{
		cin >> x;
		x *= 2;
	}
	int low = 0, high = a[n - 1];
	for (int i = 0; i < 200; ++i)
	{
		int left1 = (low) + (high - low) / 2;
		if (high - low < 200)
		{
			brute(low, high, n);
			return;
		}
		ll expected1 = a[n - 1] - left1;
		ll received1 = getArr(n, left1);
		ll diff = expected1 - received1;
		if (diff < 0)
		{
			high = left1;
		}
		else
		{
			low = left1;
		}
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