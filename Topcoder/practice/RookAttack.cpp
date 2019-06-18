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

class RookAttack
{
private:
	vector<vector<bool>> G;
	int r, c;
	vector<bool> Vis;
	vector<int> Match;
	bool findMatch(int src)
	{
		if (src == -1)
			return true;
		for (int i = 0; i < c; ++i)
			if (G[src][i] && !Vis[i])
			{
				Vis[i] = true;
				if (findMatch(Match[i]))
				{
					Match[i] = src;
					return true;
				}
			}
		return false;
	}

public:
	int howMany(int rows, int cols, vector<string> cutouts)
	{
		int u, v;
		r = rows;
		c = cols;
		G.resize(r, vector<bool>(c, true));
		Vis.resize(c);
		Match.resize(c, -1);
		for (auto s : cutouts)
		{
			stringstream S(s);
			S >> u;
			S >> v;
			G[u][v] = false;
		}
		int ret = 0;
		for (int i = 0; i < r; ++i)
		{
			fill(Vis.begin().Vis.end(), false);
			ret += findMatch(i);
		}
		return ret;
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
	RookAttack S;
	while (t--)
		S.Solve();
	return 0;
}
#endif