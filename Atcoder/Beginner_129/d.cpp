//Optimise
#include <bits/stdc++.h>
using namespace std;

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

void solve()
{
	int h, w;
	cin >> h >> w;
	vector<string> S(h);
	vector<vector<int>> Count(h, vector<int>(w));
	for (auto &x : S)
		cin >> x;
	for (int i = 0; i < h; ++i)
	{
		int j, prevcnt = 0;
		for (j = 0; j < w; ++j)
		{
			if (S[i][j] == '#')
			{
				int j1 = j - 1, cnt = prevcnt;
				while (cnt--)
					Count[i][j1--] = prevcnt;
				prevcnt = 0;
			}
			else
				prevcnt++;
		}
		int j1 = j - 1, cnt = prevcnt;
		while (cnt--)
			Count[i][j1--] = prevcnt;
		// prevcnt = 0;
	}
	ll answer = 0;
	for (int i = 0; i < w; ++i)
	{
		int j, prevcnt = 0;
		for (j = 0; j < h; ++j)
		{
			if (S[j][i] == '#')
			{
				int j1 = j - 1, cnt = prevcnt;
				while (cnt--)
					answer = max(answer, (ll)prevcnt + Count[j1--][i]);
				prevcnt = 0;
			}
			else
				prevcnt++;
		}
		int j1 = j - 1, cnt = prevcnt;
		while (cnt--)
			answer = max(answer, (ll)prevcnt + Count[j1--][i]);
		prevcnt = 0;
	}
	cout << max(0LL, answer - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	while (t--)
		solve();
	return 0;
}