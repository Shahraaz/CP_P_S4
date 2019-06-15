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
	int n, x;
	cin >> n;
	vector<int> A;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		A.pb(x);
	}
	sort(A.begin(), A.end());
	ll answer = -A[0] + A[n - 1];
	for (int i = 0; i < n - 2; ++i)
		answer += abs(A[i + 1]);
	cout << answer << '\n';
	int ptr = n - 2;
	ll minLowSum = A[0];
	while (ptr > 0 && A[ptr] > 0)
	{
		cout << minLowSum << ' ' << A[ptr] << '\n';
		minLowSum -= A[ptr];
		ptr--;
	}
	cout << A[n - 1] << ' ' << minLowSum << '\n';
	minLowSum = A[n - 1] - minLowSum;
	while (ptr > 0)
	{
		cout << minLowSum << ' ' << A[ptr] << '\n';
		minLowSum -= A[ptr];
		ptr--;
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