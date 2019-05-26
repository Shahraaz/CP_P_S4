//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Online 1
// #define multitest 1
// #define Debug 1
typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;
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

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> V;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		V.pb(x);
	}
	ll answer = 0;
	priority_queue<int, vector<int>, greater<int>> Q;
	for (int leftcnt = 0; leftcnt <= n; ++leftcnt)
	{
		if (leftcnt)
			Q.push(V[leftcnt - 1]);
		if (Q.size() > k)
			break;
		auto q1 = Q;
		for (int right = 0; right <= n; right++)
		{
			if (right)
				Q.push(V[n - right]);
			if (Q.size() > k)
				break;
			if (Q.size() > n)
				break;
			db(leftcnt, right, Q.size());
			int Remove = k - Q.size();
			while (Remove >= 0)
			{
				int r = Remove;
				Remove--;
				auto q2 = Q;
				ll sum = 0;
				while (Q.size())
				{
					if (r)
					{
						if (Q.top() < 0)
							r--;
						else
							sum += Q.top();
					}
					else
						sum += Q.top();
					Q.pop();
				}
				if (sum > answer)
					db(leftcnt, right, Remove + 1, q2.size());
				answer = max(answer, sum);
				Q = q2;
			}
		}
		Q = q1;
	}
	cout << answer;
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