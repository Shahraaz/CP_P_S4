//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Online 1
// #define multitest 1
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

class PartitionArray
{
private:
	/* data */
public:
	vector<int> positiveSum(vector<int> a)
	{
		int sum = a[0];
		int n = a.size();
		for (int i = 1; i < n; ++i)
		{
			sum += a[i];
		}
		int sum2 = a[0];
		sum -= a[0];
		vector<int> temp;
		for (int i = 1; i < n; ++i)
		{
			if (sum > 0 && sum2 > 0)
			{
				temp.pb(i);
				temp.pb(n - i);
				return temp;
			}
			sum2 += a[i];
			sum -= a[i];
		}
		temp.pb(-1);
		return temp;
	}
};

#ifndef Online
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	Solver S;
	while (t--)
		S.Solve();
	return 0;
}
#endif