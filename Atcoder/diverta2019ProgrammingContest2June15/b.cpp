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

ll solve(vector<pair<int, int>> &v, int p, int q)
{
	// db(p,q);
	if (p == 0 && q == 0)
		return 1e18;
	int n = v.size();
	vector<bool> vis(n);
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (vis[i])
			continue;
		cnt++;
		pair<int, int> curr = v[i];
		if (binary_search(v.begin(), v.end(), make_pair(v[i].f + p, v[i].s + q)))
		{
			auto it = lower_bound(v.begin(), v.end(), make_pair(curr.f + p, curr.s + q));
			while (it != v.end())
			{
				if (it->f != (curr.f + p))
					break;
				if (it->s != (curr.s + q))
					break;
				int j = it - v.begin();
				db(curr.f, curr.s, curr.f + p, curr.s + q, i, j);
				if (vis[j])
					break;
				vis[j] = true;
				curr = v[j];
				it = lower_bound(v.begin(), v.end(), make_pair(curr.f + p, curr.s + q));
			}
		}
		vis[i] = true;
	}
	db(cnt, p, q) 
	return cnt;
}

void solve()
{
	int n;
	cin >> n;
	vector<pair<int, int>> V(n);
	for (auto &x : V)
		cin >> x.f >> x.s;
	sort(V.begin(), V.end());
	ll answer = n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				continue;
			ll temp = solve(V, V[j].f - V[i].f, V[j].s - V[i].s);
			answer = min(answer, temp);
		}
	cout << answer << '\n';
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