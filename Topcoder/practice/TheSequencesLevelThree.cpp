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
const long long mod = 1234567891;

class TheSequencesLevelThree
{
private:
	long long f[99][99];

public:
	int find(vector<int> sequence, int k)
	{
		int n = sequence.size(), i, j;
		ll ans = 0;
		if (n < 3)
			return 0;
		sort(sequence.rbegin(), sequence.rend());
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for (i = 0; i < n; i++)
			for (j = i; j < n; ++j)
			{
				if (j == n - 1)
				{
					if (i)
						ans = (ans + f[i][j]) % mod;
				}
				else
				{
					if (sequence[i] - sequence[j + 1] <= k)
						f[i][j + 1] = (f[i][j + 1] + f[i][j]) % mod;
					if (sequence[j] - sequence[j + 1] <= k)
						f[i][j + 1] = (f[i][j + 1] + f[i][j]) % mod;
				}
			}
		return ans;
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