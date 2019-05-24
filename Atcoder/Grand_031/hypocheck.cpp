//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Online 1
#define multitest 1
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
bool isPowerOfTwo(unsigned int x)
{
    // First x in the below expression is
    // for the case when x is 0
    return x && (!(x & (x - 1)));
}

// function to check whether the two numbers
// differ at one bit position only
bool differAtOneBitPos(unsigned int a, unsigned int b)
{
    return isPowerOfTwo(a ^ b);
}

void permute(vector<int> &a, int l, int r)
{
    int i;
    if (l == r)
    {
        bool k = true;
        for (int i = 0; i < 7; ++i)
        {
            bool t = differAtOneBitPos(a[i], a[i + 1]);
            k &= t;
        }
        bool t = differAtOneBitPos(a[0], a[7]);
        if (k)
        {
            for(auto x : a)
                cout << x << ' ';
            cout << '\n';
            // cout << a[0] << ' ' << a[7] << '\n';
        }
    }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a[l]), (a[i]));
            permute(a, l + 1, r);
            swap((a[l]), (a[i]));
        }
    }
}

void solve()
{
    vector<int> a(8);
    for (int i = 0; i < 8; ++i)
        a[i] = i;
    permute(a, 0, 7);
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
