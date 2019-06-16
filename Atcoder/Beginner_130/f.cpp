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

vector<int> x, y;
vector<char> d;
int n;

ld calc(ld time)
{
	ld xmin = 1e18, ymin = 1e18;
	ld xmax = -1e18, ymax = -1e18;
	for (int i = 0; i < n; ++i)
	{
		ld cx = x[i];
		ld cy = y[i];
		switch (d[i])
		{
		case 'R':
			cx += time;
			break;
		case 'L':
			cx -= time;
			break;
		case 'U':
			cy += time;
			break;
		case 'D':
			cy -= time;
			break;
		}
		xmin = min(xmin, cx);
		xmax = max(xmax, cx);
		ymin = min(ymin, cy);
		ymax = max(ymax, cy);
	}
	return (xmax - xmin) * (ymax - ymin);
}

ld ternary_search(ld low, ld high)
{
	for (int i = 0; i <= 500; ++i)
	{
		ld m1 = (low * 2 + high) / 3;
		ld m2 = (low + 2 * high) / 3;
		if (calc(m1) < calc(m2))
			high = m2;
		else
			low = m1;
	}
	return calc(low);
}

void solve()
{
	cin >> n;
	x.resize(n);
	y.resize(n);
	d.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i] >> d[i];
	cout << fixed << setprecision(12) << ternary_search(0, 2e8) << '\n';
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