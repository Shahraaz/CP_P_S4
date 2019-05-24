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

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

vector<ll> Lgcd,Rgcd;

void solve()
{
    int n;
    cin >> n;
    vector<ll> V(n);
    Lgcd.resize(n);
    Rgcd.resize(n);
    for(int i=0;i<n;++i)
        cin >> V[i];
    Lgcd[0] = V[0];
    for(int i=1;i<n;++i)
        Lgcd[i] = gcd(Lgcd[i-1],V[i]);
    Rgcd[n-1] = V[n-1];
    for(int i=n-2;i>=0;--i)
        Rgcd[i] = gcd(Rgcd[i+1],V[i]);
    ll maxi = -mod;
    maxi = Rgcd[0];
    for(int i=1;i<n-1;++i)
        maxi = max(maxi,gcd(Lgcd[i-1],Rgcd[i+1]));
    maxi = max(maxi,Lgcd[n-1]);
    cout << maxi;
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
