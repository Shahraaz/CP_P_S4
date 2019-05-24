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
#define int long long

void solve()
{
  int n,m;
  cin >> n >> m;
  vector<pair<int,int>> V(n);
  for(int i=0;i<n;++i)
    cin >> V[i].f >> V[i].s;
  sort(V.begin(),V.end());
  int amt = 0;
  for(int i=0;i<n && m;++i)
  {
    int x = min(m,V[i].s);
    m -= x;
    amt += x*V[i].f;
  }
  cout << amt;
}

main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int t = 1;
//  cin >> t;
  while(t--)
    solve();
  return 0;
}
