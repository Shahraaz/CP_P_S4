//Optimise
#include <bits/stdc++.h>
using namespace std;

// #define multitest 1
// #define Debug 1
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

const int nax = 3e2 + 5;
ld p[nax][nax][nax], ev[nax][nax][nax];

void solve()
{
	int n, x;
	cin >> n;
	vector<int> cnt(4);
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		cnt[x]++;
	}
	p[cnt[1]][cnt[2]][cnt[3]] = 1;
	for (int c = n; c >= 0; --c)
		for (int b = n; b >= 0; --b)
			for (int a = n; a >= 0; --a)
			{
				if ((a + b + c) == 0)
					continue;
				if (a + b + c > n)
					continue;
				ld p_waste = (ld)(n - a - b - c) / n;
				ld ev_waste = p_waste / (1 - p_waste) + 1;
				ev[a][b][c] += ev_waste * p[a][b][c];
				if (a != 0)
				{
					ld p_go = (ld)a / (a + b + c);
					p[a - 1][b][c] += p[a][b][c] * p_go;
					ev[a - 1][b][c] += ev[a][b][c] * p_go;
				}
				if (b != 0)
				{
					ld p_go = (ld)b / (a + b + c);
					p[a + 1][b - 1][c] += p[a][b][c] * p_go;
					ev[a + 1][b - 1][c] += ev[a][b][c] * p_go;
				}
				if (c != 0)
				{
					ld p_go = (ld)c / (a + b + c);
					p[a][b + 1][c - 1] += p[a][b][c] * p_go;
					ev[a][b + 1][c - 1] += ev[a][b][c] * p_go;
				}
			}
	cout << fixed << setprecision(15);
	cout << ev[0][0][0];
}

int main()
{
#ifndef Debug
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#endif
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	while (t--)
		solve();
	return 0;
}