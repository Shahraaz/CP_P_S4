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

class VectorMatching
{
private:
	/* data */
public:
	double minimumLength(vector<int> x, vector<int> y)
	{
		int n = x.size();
		ll res = LLONG_MAX;
		for (int i = 0; i < (1 << n); ++i)
			if ((2 * __builtin_popcount(i)) == n)
			{
				ll sx, sy;
				sx = sy = 0;
				for (int j = 0; j < n; ++j)
					if (i & (1 << j))
					{
						sx += x[j];
						sy += y[j];
					}
					else
					{
						sx -= x[j];
						sy -= y[j];
					}
				res = min(res, sx * sx + sy * sy);
			}
		return sqrtl(res);
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