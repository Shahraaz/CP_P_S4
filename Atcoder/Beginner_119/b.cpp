//Optimise
#include<bits/stdc++.h>

using namespace std;
#define f first
#define s second
#define pb push_back
 
typedef long long ll;
typedef long double ld;

void solve()
{
	int n;
	cin >> n;
	ld ans , temp ;
	ans = 0;
	string str;
	while(n--)
	{
		cin >> temp >> str;
		if(str=="BTC")
			ans += temp * 380000;
		else ans += temp;
	}
	cout << fixed << setprecision(9) << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
//	cin >> t;
	while(t--)
		solve();
	return 0;
}
