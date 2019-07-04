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

const int nax = 1e5 + 5;
vector<int> edges[nax];
int in_degree[nax], dist[nax];
bool visited[nax];

void dfs(int node)
{
	if (visited[node])
		return;
	visited[node] = true;
	for (auto child : edges[node])
	{
		dist[child] = max(dist[node] + 1, dist[child]);
		in_degree[child]--;
		if (in_degree[child] == 0)
			dfs(child);
	}
	db(node,dist[node]);
}

void solve()
{
	int n, m, u, v;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		edges[u].pb(v);
		in_degree[v]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (in_degree[i] == 0)
			dfs(i);
	for (int i = 1; i <= n; ++i)
		ans = max(ans, dist[i]);
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