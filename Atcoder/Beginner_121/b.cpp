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
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> B(m);
  vector<vector<int>> A(n, vector<int>(m));
  for (int i = 0; i < m; ++i)
    cin >> B[i];
  int ans = 0;
  for (int i = 0; i < n; ++i)
  {
    int sum = c;
    for (int j = 0; j < m; ++j)
    {
      cin >> A[i][j];
      sum += B[j]*A[i][j];
    }
    if(sum>0) ans++;
  }
  cout << ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t = 1;
  //  cin >> t;
  while (t--)
    solve();
  return 0;
}
