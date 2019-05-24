//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Online 1
// #define multitest 1
// #define Debug
typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;
const long long High = 1e16;
void ControlIO();
void TimerStart();
void TimerStop();
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__)
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

typedef pair<int, int> pii;

void solve()
{
	vector<vector<bool>> G_Comp;
	int n;
	cin >> n;
	G_Comp.resize(n + 1, vector<bool>(n + 1));
	if (n & 1)
	{
		for (int i = 1; i <= n; ++i)
		{
			G_Comp[i][n - i] = true;
			G_Comp[n - i][i] = true;
		}
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			G_Comp[i][n - i + 1] = true;
			G_Comp[n - i + 1][i] = true;
		}
	}
	vector<pii> Ans;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
				continue;
			if (G_Comp[i][j]==false)
			{
				G_Comp[i][j] = G_Comp[j][i] = true;
				Ans.pb(mp(i, j));
			}
		}
	cout << Ans.size() << '\n';
	for (auto x : Ans)
		cout << x.f << ' ' << x.s << '\n';
}

main()
{
	ControlIO();
	int t = 1;
#ifdef multitest
	cin >> t;
	// cout << t << '\n';
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