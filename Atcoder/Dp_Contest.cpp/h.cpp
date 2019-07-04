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

template <typename T>
void add(T &a, T b)
{
	a = (ll(a) + b) % mod;
}

void solve()
{
	int h, w;
	cin >> h >> w;
	vector<string> grid(h);
	for (auto &a : grid)
		cin >> a;
	vector<vector<int>> Dp(h, vector<int>(w));
	Dp[0][0] = 1;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			for (int x : {i, i + 1})
			{
				int y = j;
				if (x == i)
					y++;
				if (x < h && y < w && grid[x][y] == '.')
					add(Dp[x][y], Dp[i][j]);
				db(i, j, Dp[i][j]);
				db(x, y, Dp[x][y],grid[x][y]);
			}
	cout << Dp[h - 1][w - 1] << '\n';
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