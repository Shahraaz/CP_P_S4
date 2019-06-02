//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Online 1
// #define multitest 1
#define Debug 1
void ControlIO();
void TimerStart();
void TimerStop();
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
	int n, u, v;
	cin >> n;
	vector<vector<int>> G(n);
	vector<int> Degree(n);
	for (int i = 1; i < n; ++i)
	{
		cin >> u >> v;
		--u;
		--v;
		G[u].pb(v);
		G[v].pb(u);
		Degree[u]++;
		Degree[v]++;
	}
	vector<int> s(n);
	vector<int> vis(n);
	vector<int> value(n);
	for (auto &x : s)
		cin >> x;
	sort(s.begin(), s.end());
	reverse(s.begin(),s.end());
	queue<int> Q;
	for (int i = 0; i < n; ++i)
		if (Degree[i] == 1)
			Q.push(i);
	while (!Q.empty())
	{
		auto t = Q.front();
		Q.pop();
		value[t] = s.back();
		s.pop_back();
		for (auto x : G[t])
		{
			if (!vis[x])
			{
				Degree[x]--;
				if (Degree[x] == 1)
				{
					vis[x] = true;
					Q.push(x);
				}
			}
		}
	}
	ll max = 0,i=0;
	for (auto x : G)
	{
		for (auto y : x)
			max += min(value[i],value[y]);
		++i;
	}
	cout << max/2 << '\n';
	for(auto x:value)
		cout << x << ' ';
}

int main()
{
	ControlIO();
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	TimerStart();
	while (t--)
		solve();
	TimerStop();
	return 0;
}

void ControlIO()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef Online
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();

void TimerStart()
{
#ifndef Online
	TimeStart = chrono::steady_clock::now();
#endif
}

void TimerStop()
{
#ifndef Online
	TimeEnd = chrono::steady_clock::now();
	auto ElapsedTime = TimeEnd - TimeStart;
	cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
#endif
}