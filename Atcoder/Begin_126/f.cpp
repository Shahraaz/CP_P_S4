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

void solve()
{
    int m, k;
    cin >> m >> k;
    vector<int> V;
    int n = (int)pow(2, m + 1);
    for (int i = 0; i < n; ++i)
        V.pb(i / 2);
    if(1==m && k==1)
    {
        cout << -1;
        return;
    }
    
    if (k == 0)
    {
        for (int i = 0; i < n; ++i)
            cout << V[i] << ' ';
        return;
    }
    else if (k <= V[n - 1])
    {
        set<int> S;
        for (int i = 0; i < n; ++i)
        {
            if (V[i] == k)
                continue;
            S.insert(V[i]);
        }
        vector<int> X;
        for(auto it=S.begin();it!=S.end();++it)
        {
            X.pb(*it);
            cout << *it << ' ';
        }
        cout << k << ' ';
        reverse(X.begin(),X.end());
        for(auto x : X)
            cout << x << ' ' ;
        cout << k ;
    }
    else
        cout << -1;
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