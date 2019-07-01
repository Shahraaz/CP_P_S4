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

class BouncingBalls
{
private:
	/* data */
public:
	double expectedBounces(vector<int> x, int T)
	{
		int cnt = 0;
		int n = x.size();
		for (int i = 0; i < (1 << n); ++i)
		{
			vector<int> Dir(n, -1);
			for (int k = 0; k < n; ++k)
				if (i & (1 << k))
					Dir[k] = 1;
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < n; ++k)
					if (x[k] < x[j] && Dir[j] == 1 && Dir[k] == -1 && x[j] - x[k] <= 2 * T)
						cnt++;
		}
		return (1.0 * cnt) / (1 << n);
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