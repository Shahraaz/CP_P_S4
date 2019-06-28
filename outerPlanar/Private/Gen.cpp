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

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
auto my_rand = std::bind(std::uniform_int_distribution<int>(0, 1e5), mt19937(seed));
typedef vector<int> vi;
typedef vector<vi> _graph;
struct graph
{
	int n, m;
	_graph G;
	graph(int _n)
	{
		db(_n);
		n = _n;
		G.resize(n);
		if (n <= 1)
			return;
		for (int i = 0; i < n; ++i)
		{
			G[i].pb((i + 1) % n);
			G[(i + 1) % n].pb(i);
		}
		if (n <= 3)
			return;
		// int one = my_rand() % n;
		int two = my_rand() % n;
		while (true)
		{
			two = my_rand() % n;
			if (two == 0)
				continue;
			if (two == 1)
				continue;
			if (two == (n - 1))
				continue;
			break;
		}
		if (true)
		{
			db("Taken");
			G[0].pb(two);
			G[two].pb(0);
		}
		db(two);
		int s1 = two + 1;
		int s2 = n - two + 1;
		auto g1 = graph(s1);
		auto g2 = graph(s2);
		auto G1 = g1.G;
		auto G2 = g2.G;
		int off = my_rand() % s1;
		for (int i = 0; i < s1; ++i)
		{
			for (auto j : G1[i])
			{
				if (i == (j + 1) % s1)
					continue;
				if (j == (i + 1) % s1)
					continue;
				int i1 = i;
				i1 = (i1 + off) % s1;
				j = (j + off) % s1;
				db(i1, j, s1, n);
				G[i1].pb(j);
				G[j].pb(i1);
			}
		}
		db("TWO");
		off = my_rand() % s2;
		for (int i = 0; i < s2; ++i)
		{
			for (auto j : G2[i])
			{
				if (i == (j + 1) % s2)
					continue;
				if (j == (i + 1) % s2)
					continue;
				int i1 = i;
				i1 = (i1 + off) % s2;
				j = (j + off) % s2;
				if (i1 != 0)
					i1 += two - 1;
				if (j != 0)
					j += two - 1;
				db(i1, j, s1, n);
				G[i1].pb(j);
				G[j].pb(i1);
			}
		}
		for (int i = 0; i < n; ++i)
		{
			sort(G[i].begin(), G[i].end());
			G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
		}
	}
};

void solve()
{
	int n;
	cin >> n;
	auto g = graph(n);
	auto G = g.G;
	cout << n << '\n';
	int m = 0;
	for (int i = 0; i < n; ++i)
		for (auto x : G[i])
		{
			if (i < x)
				m++;
		}
	cout << 3 << '\n';
	for (int i = 0; i < n; ++i)
		for (auto x : G[i])
		{
			if (i < x)
			{
				// cout << i + 1 << ' ' << x + 1 << '\n';
				int i1 = i + 1;
				int x1 = x + 1;
				if (i1 < 10)
					cout << 0 << i1 << ' ';
				else cout << i1 << ' ';
				if (x1 < 10)
					cout << 0 << x1 << '\n';
				else cout << x1 << '\n';
			}
		}
}

int main()
{
	// freopen("Gen.in", "r", stdin);
	freopen("Gen.ou", "w", stdout);
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