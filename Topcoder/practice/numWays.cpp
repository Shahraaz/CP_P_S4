//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Online 1
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

class AvoidRoads
{
private:
	/* data */
public:
	vector<vector<ll>> Dp;
	int width, height;
	set<pair<pair<int, int>, pair<int, int>>> Forbidden;

	ll solve(int i, int j)
	{
		if (i < 0 || j < 0)
			return 0;
		if (i == 0 && j == 0)
			return 1;
		if (Dp[i][j] >= 0)
			return Dp[i][j];
		int i1 = i - 1;
		int j1 = j - 1;
		ll ans = 0;
		if (!Forbidden.count({{i, j}, {i1, j}}))
			ans += solve(i1, j);
		if (!Forbidden.count({{i, j}, {i, j1}}))
			ans += solve(i, j1);
		return Dp[i][j] = ans;
	}

	long long numWays(int width, int height, vector<string> bad)
	{
		for (auto s : bad)
		{
			stringstream SS(s);
			int a, b, c, d;
			SS >> a >> b >> c >> d;
			Forbidden.insert({{a, b}, {c, d}});
			Forbidden.insert({{c, d}, {a, b}});
		}
		Dp = vector<vector<ll>>(width + 1, vector<ll>(height + 1, -1));
		return solve(width, height);
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
	Solver S;
	while (t--)
		S.Solve();
	return 0;
}
#endif