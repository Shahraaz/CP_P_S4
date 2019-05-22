//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Online 1
// #define multitest 1
// #define Debug
typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;
const long long High = 1e16;
void ControlIO();
void TimerStart();
void TimerStop();
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__)
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

void solve()
{
	int n;
	cin >> n;
	vector<int> V(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> V[i];
		V[i]--;
	}
	stack<int> St;
	int size = n;
	while (size > 0)
	{
		int i;
		bool t = false;
		for (i = size - 1; i >= 0; --i)
		{
			if (V[i] == i)
			{
				St.push(V[i]);
				for (int j = i; j < size; ++j)
				{
					V[j] = V[j + 1];
				}
				size--;
				t = true;
				break;
			}
		}
		if (t)
			continue;
		cout << -1 << '\n';
		return;
	}
	while (!St.empty())
	{
		cout << St.top() + 1 << '\n';
		St.pop();
	}
	cout << '\n';
}

main()
{
	ControlIO();
	int t = 1;
#ifdef multitest
	cin >> t;
	// cout << t << '\n';
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