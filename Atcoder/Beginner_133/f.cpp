/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  "An ideal problem has no test data."
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma warning(disable : 4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("-ffloat-store")

#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fo(i, n) for (i = 0; i < (n); ++i)
#define repA(i, j, n) for (i = (j); i <= (n); ++i)
#define repD(i, j, n) for (i = (j); i >= (n); --i)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"
typedef long long int lli;
typedef long double mytype;
typedef pair<lli, lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

clock_t time_p = clock();
void aryanc403()
{
	time_p = clock() - time_p;
	cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}

#ifdef ARYANC403
#define dbg(...)                                  \
	{                                             \
		cerr << "[ ";                             \
		__aryanc403__(#__VA_ARGS__, __VA_ARGS__); \
	}
#undef endl
template <typename Arg1, typename Arg2>
ostream &operator<<(ostream &out, const pair<Arg1, Arg2> &x)
{
	return out << "(" << x.X << "," << x.Y << ")";
}

template <typename Arg1>
ostream &operator<<(ostream &out, const vector<Arg1> &a)
{
	out << "[";
	for (const auto &x : a)
		out << x << ",";
	return out << "]";
}

template <typename Arg1>
ostream &operator<<(ostream &out, const set<Arg1> &a)
{
	out << "[";
	for (const auto &x : a)
		out << x << ",";
	return out << "]";
}

template <typename Arg1, typename Arg2>
ostream &operator<<(ostream &out, const map<Arg1, Arg2> &a)
{
	out << "[";
	for (const auto &x : a)
		out << x << ",";
	return out << "]";
}

template <typename Arg1>
void __aryanc403__(const string name, Arg1 &&arg1)
{
	cerr << name << " : " << arg1 << " ] " << endl;
}

template <typename Arg1, typename... Args>
void __aryanc403__(const string names, Arg1 &&arg1, Args &&... args)
{
	const string name = names.substr(0, names.find(','));
	cerr << name << " : " << arg1 << " | ";
	__aryanc403__(names.substr(1 + (int)name.size()), args...);
}

#else
#define dbg(args...)
#endif

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed = chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l = 0, lli r = INF)
{
	return uniform_int_distribution<lli>(l, r)(rng);
}

class CMP
{
public:
	bool operator()(ii a, ii b) //For min priority_queue .
	{
		return !(a.X < b.X || a.X == b.X && a.Y <= b.Y);
	}
};

void add(map<lli, lli> &m, lli x, lli cnt = 1)
{
	auto jt = m.find(x);
	if (jt == m.end())
		m.insert({x, cnt});
	else
		jt->Y += cnt;
}

void del(map<lli, lli> &m, lli x, lli cnt = 1)
{
	auto jt = m.find(x);
	if (jt->Y <= cnt)
		m.erase(jt);
	else
		jt->Y -= cnt;
}

bool cmp(const ii &a, const ii &b)
{
	return a.X < b.X || (a.X == b.X && a.Y < b.Y);
}

const lli mod = 1000000007L;
const lli maxN = 2 * 100000L;
const lli logN = 20;

lli T, n, i, j, k, in, cnt, l, r, u, v, x, y;
lli m, q, c, w;
string s;
vector<pair<lli, ii>> e[maxN + 5];
lli h[maxN + 5], p[logN + 5][maxN + 5];
lli tin[maxN + 5], tout[maxN + 5];
map<lli, lli> flen[4 * maxN + 5], fcnt[4 * maxN + 5];
vii elr;
//priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

bool isAnc(lli l, lli u)
{
	return tin[l] <= tin[u] && tout[u] <= tout[l];
}

lli lca(lli u, lli v)
{
	if (isAnc(v, u))
		return v;
	swap(u, v);
	if (isAnc(v, u))
		return v;
	lli i;
	repD(i, logN, 0) if (!isAnc(p[i][u], v))
		u = p[i][u];
	u = p[0][u];
	return u;
}

void dfs(lli u, lli pa, lli s)
{
	h[u] = s;
	p[0][u] = pa;
	tin[u] = ++T;
	lli i;
	repA(i, 1, logN)
		p[i][u] = p[i - 1][p[i - 1][u]];

	for (auto x : e[u])
	{
		if (x.X == pa)
			continue;
		elr.pb(x.Y);
		dfs(x.X, u, s + x.Y.Y);
		elr.pb({x.Y.X, -x.Y.Y});
	}
	tout[u] = ++T;
}

ii query(lli id, lli l, lli r, lli L, lli R, lli c)
{
	if (R < l || r < L)
		return {0, 0};
	if (L <= l && r <= R)
	{
		ii ans = {0, 0};
		auto it = flen[id].find(c);
		if (it != flen[id].end())
			ans = {flen[id][c], fcnt[id][c]};
		return ans;
	}
	lli m = (l + r) / 2;
	ii a, b;
	a = query(2 * id, l, m, L, R, c);
	b = query(2 * id + 1, m + 1, r, L, R, c);
	return {a.X + b.X, a.Y + b.Y};
}

lli solve(lli l, lli u, lli c, lli len)
{
	if (l == u)
		return 0;
	lli ans = h[u] - h[l];
	ii x = query(1, 1, T, tin[l], tin[u] - 1, c); //sum,cnt;
	dbg(x, l, u, c);
	ans -= x.X;
	ans += len * x.Y;
	return ans;
}

void build(lli id, lli l, lli r)
{
	lli i;
	repA(i, l, r)
	{
		flen[id][elr[i].X] += elr[i].Y;
		fcnt[id][elr[i].X] += elr[i].Y / abs(elr[i].Y);
	}
	if (l == r)
		return;
	lli m = (l + r) / 2;
	build(2 * id, l, m);
	build(2 * id + 1, m + 1, r);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// freopen("txt.in", "r", stdin);
	// freopen("txt.out", "w", stdout);
	// cout<<std::fixed<<std::setprecision(35);
	// cin>>T;while(T--)
	{

		cin >> n >> q;
		elr.pb({0, 0}); //col,len;
		fo(i, n - 1)
		{
			cin >> u >> v >> c >> w;
			e[u].pb({v, {c, w}});
			e[v].pb({u, {c, w}});
		}

		dfs(1, 1, 0);
		T -= 2;
		dbg(T, (lli)elr.size());
		build(1, 1, T);
		dbg(elr);
		dbg(tin[1], tin[4], tin[5]);
		while (q--)
		{
			cin >> x >> y >> u >> v;
			l = lca(u, v);
			cout << solve(l, u, x, y) + solve(l, v, x, y) << endl;
		}
	}
	aryanc403();
	return 0;
}