//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Online 1
// #define multitest 1
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

vector<ll> Dp(200005);
int n;
// vector<vector<int>> C(200005);
vector<int> Dist;

ll Dp_com()
{
	int n = Dist.size() - 1;
	vector<int> Cumm(200005);
	Dp[n] = 1;
	// db(Dist[n]);
	Cumm[Dist[n]] = 1;
	for (int i = n - 1; i >= 0; --i)
	{
		// db(Dist[i]);
		Dp[i] = Dp[i + 1] + Cumm[Dist[i]];
		Dp[i] %= mod;
		// db(i,Dp[i]);
		Cumm[Dist[i]] += Dp[i+1];
		Cumm[Dist[i]] %= mod;
	}
	return Dp[0];
}

void solve()
{
	cin >> n;
	int k, prev = -1;
	for (int i = 0; i < n; ++i)
	{
		cin >> k;
		if (k == prev)
			continue;
		// if(fisrt==-1) first = k;
		Dist.pb(k);
		// C[k].pb(Dist.size() - 1);
		prev = k;
	}
	cout << Dp_com() << '\n';
	// for(auto it : Dp)
	// 	db(it.f,it.s);
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
