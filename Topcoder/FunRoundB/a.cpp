//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Online 1
#define Debug 1
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
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
typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class MedianFaking
{
private:
	/* data */
public:
	vector<int> minimize(int F, int M, vector<int> data, int goal)
	{
		typedef pair<int, int> pii;
		vector<pii> a;
		int n = data.size();
		for (int i = 0; i < n; ++i)
			a.pb({data[i], i / F});
		sort(a.begin(), a.end());
		int med = a[n / 2].f;
		vector<int> Changed;
		vector<int> ans;
		if (data[n / 2] == goal)
		{
			ans.pb(0);
			ans.pb(0);
		}
		else
		{
			int x = F - 1;
			
		}
		return ans;
	}
};

#ifndef Online
int main()
{
	TClass T;
	cout << T.solve();
	return 0;
}
#endif