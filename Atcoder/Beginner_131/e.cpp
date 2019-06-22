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

void solve()
{
	int n, k;
	cin >> n >> k;
	int max = (n - 1) * (n - 2) / 2;
	if (k > max)
		cout << -1;
	else
	{
		vector<pair<int, int>> Adj;
		for (int i = 1; i < n; ++i)
			Adj.pb({i, n});
		int m = n - 1;
		int curr = 1;
		int i = 2;
		while (k < max)
		{
			db(k,max);
			Adj.pb({curr, i});
			++i;
			if (i == n)
			{
				curr++;
				i = curr + 1;
			}
			max--;
		}
		cout << Adj.size() << '\n';
		for (auto x : Adj)
			cout << x.f << ' ' << x.s << '\n';
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