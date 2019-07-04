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

vector<ll> Tree;

ll query(int node, int start, int end, int qstart, int qend)
{
	if (start > end || qend < start || qstart > end)
		return 0;
	if (qstart <= start && end <= qend)
		return Tree[node];
	int mid = (start + end) / 2;
	return max(query(2 * node, start, mid, qstart, qend),
			   query(2 * node + 1, mid + 1, end, qstart, qend));
}

void update(int node, int start, int end, int pos, ll val)
{
	if (start > end)
		return;
	if (start == end)
	{
		Tree[node] = max(Tree[node], val);
		return;
	}
	int mid = (start + end) / 2;
	if (pos <= mid)
		update(2 * node, start, mid, pos, val);
	else
		update(2 * node + 1, mid + 1, end, pos, val);
	Tree[node] = max(Tree[node * 2], Tree[node * 2 + 1]);
}

void solve()
{
	int n;
	cin >> n;
	Tree.resize(4 * n);
	vector<int> h(n), a(n);
	for (auto &x : h)
	{
		cin >> x;
		--x;
	}
	for (auto &x : a)
		cin >> x;
	vector<ll> dp(n + 1);
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int x = h[i];
		ll q = query(1, 0, n - 1, 0, x - 1);
		dp[x] = max(dp[x], q + a[i]);
		db(q, x, dp[x]);
		ans = max(ans, dp[x]);
		update(1, 0, n - 1, x, dp[x]);
	}
	cout << ans;
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