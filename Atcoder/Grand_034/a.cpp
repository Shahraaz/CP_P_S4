//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Online 1
// #define multitest 1
#define Debug 1
void ControlIO();
void TimerStart();
void TimerStop();
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

bool f(string &s, int a, int b)
{
	if (a == b)
		return true;
	if (a > b)
		return false;
	if (a == s.length() || s[a] == '#')
		return false;
	return f(s, a + 1, b) || f(s, a + 2, b);
}

void solve()
{
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	string s;
	cin >> s;
	int cnt = 0, cnt2 = 0;
	// bool f = false;
	for (int i = a - 1; i < max(c, d); ++i)
	{
		if (s[i] == '#')
		{
			// cnt2 = 0;
			cnt++;
		}
		else
		{
			// cnt2++;
			cnt = 0;
		}
		if (cnt == 2)
		{
			cout << "No\n";
			return;
		}
	}
	// s[b - 1] = '#';
	if (f(s, b - 1, d - 1))
	{
		s[d - 1] = '#';
		// s[b - 1] = '.';
		if (f(s, a - 1, c - 1))
		{
			cout << "Yes\n";
			return;
		}
		s[d - 1] = '.';
	}
	s[b - 1] = '#';
	if (f(s, a - 1, c - 1))
	{
		s[c - 1] = '#';
		s[b - 1] = '.';
		// s[d - 1] = '#';
		if (f(s, b - 1, d - 1))
		{
			cout << "Yes\n";
			return;
		}
		// s[d - 1] = '.';
		s[c - 1] = '.';
	}
	s[b - 1] = '.';
	cnt = 0;
	for (int i = b - 2; i < d; ++i)
	{
		if (s[i] == '.')
			cnt++;
		else
			cnt = 0;
		if (cnt == 3)
		{
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main()
{
	ControlIO();
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	TimerStart();
	while (t--)
		solve();
	TimerStop();
	return 0;
}

void ControlIO()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef Online
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();

void TimerStart()
{
#ifndef Online
	TimeStart = chrono::steady_clock::now();
#endif
}

void TimerStop()
{
#ifndef Online
	TimeEnd = chrono::steady_clock::now();
	auto ElapsedTime = TimeEnd - TimeStart;
	cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
#endif
}