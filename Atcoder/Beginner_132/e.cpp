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
	int n, m, u, v, s, t;
	cin >> n >> m;
	vector<vector<int>> Adj(n + 1);
	while (m--)
	{
		cin >> u >> v;
		Adj[u].pb(v);
	}
	cin >> s >> t;
	vector<vector<bool>> Vis(3, vector<bool>(n + 1));
	vector<vector<int>> Dist(3, vector<int>(n + 1, mod));
	Vis[0][s] = true;
	queue<pair<int, int>> Q;
	Q.push({s, 0});
	Dist[0][s] = 0;
	while (!Q.empty())
	{
		auto top = Q.front();
		Q.pop();
		if (top.s == 0 && top.f == t)
		{
			cout << Dist[0][t] / 3 << '\n';
			return;
		}
		int next = (top.s + 1) % 3;
		for (auto child : Adj[top.f])
			if (!Vis[next][child])
			{
				Vis[next][child] = true;
				Q.push({child, next});
				Dist[next][child] = Dist[top.s][top.f] + 1;
			}
	}
	cout << -1 << '\n';
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