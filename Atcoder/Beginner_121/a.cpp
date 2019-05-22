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

void solve()
{
  int H,W,h,w;
  cin >> H >> W >> h >> w;
  cout << H*W - (h*W + w*H - w*h);
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
