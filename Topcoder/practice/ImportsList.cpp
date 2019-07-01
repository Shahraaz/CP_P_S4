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

class ImportsList
{
private:
	/* data */
public:
	vector<int> importsCount(vector<string> requires)
	{
		int n = requires.size();
		vector<ll> mask(n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (requires[i][j] == 'Y')
					mask[i] |= (1LL << j);
		vector<int> ret(n);
		for (int i = 0; i < n; ++i)
		{
			ll maskCur = mask[i];
			for (int j = 0; j < n; ++j)
				if ((mask[i] & (1LL << j)))
					maskCur = maskCur & (~mask[j]);
			ret[i] = __builtin_popcountl(maskCur);
		}
		return ret;
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