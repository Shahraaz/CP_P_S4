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
	int w, h, x, y;
	cin >> w >> h >> x >> y;
	if ((2 * x) == w && (2 * y) == h)
	{
		ld w1 = w;
		cout << fixed << setprecision(9);
		cout << w1 * h / 2 << ' ' << 1 << '\n';
	}
	else
	{
		ld w1 = w;
		// if (2 * x > w)
		// 	x = w - x;
		// if (2 * y > h)
		// 	y = h - y;
		cout << fixed << setprecision(9);
		cout << w1 * h / 2 << ' ' << 0 << '\n';
	}
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