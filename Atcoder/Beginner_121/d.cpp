//Optimise
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;
const long long High = 1e16;

ll cnt(ll n)
{
  switch (n & 3)
  {
  case 0:
    return n;
  case 1:
    return 1;
  case 2:
    return n + 1;
  case 3:
    return 0;
  }
}

void solve()
{
  ll a, b;
  cin >> a >> b;
  cout << (cnt(b) ^ cnt(a - 1));
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t = 1;
  //  cin >> t;
  while (t--)
    solve();
  return 0;
}
