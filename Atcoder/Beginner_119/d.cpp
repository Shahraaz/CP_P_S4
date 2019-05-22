//Optimise
#include<bits/stdc++.h>

using namespace std;
#define f first
#define s second
#define pb push_back
 
typedef long long ll;

void solve()
{
	ll a,b,q,x;
	cin >> a >> b >> q;
	vector<ll> S(a),T(b);
	for(int i=0;i<a;++i)
		cin >> S[i];
	for(int i=0;i<b;++i)
		cin >> T[i];
	while(q--)
	{
		cin >> x;
		ll ans = 1e16,temp;
		a = x;
		auto lows = lower_bound(S.begin(),S.end(),x);
		if(lows!=S.end())		
		{
			if(*lows==x)
			{
				temp = 0;
				auto lowt = lower_bound(T.begin(),T.end(),x);
				if(lowt!=T.end()){ if(*lowt==x) ans = min(ans,temp);}
				if(lowt!=T.begin())
				{		cout << 1 << '\n'	
					lowt--;
					ans = min(ans,temp + x - *lowt);
				}				 
			}
		}		
		if(lows!=S.begin())
		{
			lows--;
			temp = x - *lows;
			x = *lows;
			auto lowt = lower_bound(T.begin(),T.end(),x);
			if(lowt!=T.end())			
			{
				if(*lowt==x) ans = min(ans,temp);
			}
			if(lowt!=T.begin())
			{			
				lowt--;
				ans = min(ans,temp + x - *lowt);
			}				 
		}
		x = a;
		auto lowt = lower_bound(T.begin(),T.end(),x);
		if(lowt!=T.end())		
		{if(*lowt==x)
		{
			temp = 0;
			auto lows = lower_bound(S.begin(),S.end(),x);
			if(lows!=S.end())			
			{
				if(*lows==x) ans = min(ans,temp);
			}
			if(lows!=S.begin())
			{			
				lows--;
				ans = min(ans,temp + x - *lows);
			}				 
		}				
		}if(lowt!=T.begin())
		{
			lowt--;
			temp = x - *lowt;
			x = *lowt;
			auto ups = upper_bound(S.begin(),S.end(),x);
			if(lows!=S.end())			
			{
				if(*lows==x) ans = min(ans,temp);
			}
			if(lows!=T.begin())
			{			
				lows--;
				ans = min(ans,temp + x - *lows);
			}				 
		}
		cout << ans << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
