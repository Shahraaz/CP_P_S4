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

bool isSquare(int n)
{
	return (int(sqrt(n)) * int(sqrt(n))) == n;
}

void solve()
{
	int n, d;
	cin >> n >> d;
	vector<vector<int>> Point(n, vector<int>(d));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < d; ++j)
			cin >> Point[i][j];
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			int diff = 0;
			for (int k = 0; k < d; ++k)
				diff += (Point[i][k] - Point[j][k]) * (Point[i][k] - Point[j][k]);
			if (isSquare(diff))
				ans++;
		}
	}
	cout << ans;
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