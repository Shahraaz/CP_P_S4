//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Online 1
// #define multitest 1
#define Debug 1
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

typedef pair<int,int> pii;
void solve()
{
    int n,u,v,w;
    cin >> n;
    vector<vector<pii>> Adj(n);
    vector<int> Vis(n),Dis(n);
    for(int i=1;i<n;++i)
    {
        cin >> u >> v >> w;
        --u;
        --v;
        Adj[u].pb(mp(v,w));
        Adj[v].pb(mp(u,w));
    }
    queue<int> Q;
    Q.push(0);
    Vis[0] = 1;
    Dis[0] = 0;
    while(!Q.empty())
    {
        auto temp = Q.front();
        Q.pop();
        for(auto x : Adj[temp])
            if(!Vis[x.f])
            {
                Dis[x.f] = x.s + Dis[temp];
                Vis[x.f] = true;
                Q.push(x.f); 
            }
    }
    for(int i=0;i<n;++i)
        cout << (Dis[i]&1) << '\n';
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