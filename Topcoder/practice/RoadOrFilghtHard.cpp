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

class RoadOrFlightHard
{
private:
	ll dp[2][2][41];
	vector<ll> Generate(int n, ll first, ll prod, ll add, ll mod)
	{
		vector<ll> v(n);
		v[0] = first % mod;
		for (size_t i = 1; i < n; i++)
			v[i] = (prod * v[i - 1] % mod + add) % mod;
		return v;
	}

public:
	long long minTime(int N, int roadFirst, int roadProd, int roadAdd, int roadMod, int flightFirst, int flightProd, int flightAdd, int flightMod, int K)
	{
		const vector<ll> road = Generate(N, roadFirst, roadProd, roadAdd, roadMod);
		const vector<ll> flight = Generate(N, flightFirst, flightProd, flightAdd, flightMod);
		memset(dp, 0, sizeof(dp));
		for (int i = N - 1; i >= 0; --i)
		{
			const int me = i & 1, she = 1 - me;
			for (int fl = 0; fl < 2; ++fl)
				for (int k = 0; k <= K; ++k)
				{
					ll &best = dp[me][fl][k];
					best = dp[she][0][k] + road[i];
					if (fl)
						best = min(best, dp[she][1][k] + flight[i]);
					else if (k > 0)
						best = min(best, dp[she][1][k - 1] + flight[i]);
				}
		}
		return dp[0][0][K];
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