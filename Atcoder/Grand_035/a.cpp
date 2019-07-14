//Optimise
#include <bits/stdc++.h>
using namespace std;

// #define multitest 1
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

using ll = long long;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;
auto TimeStart = chrono::steady_clock::now();

const int nax = 1e5 + 10;
vector<int> A;

bool make(int a, int b)
{
	if (a == b)
		return true;
	if ((a + 1) == b)
		return true;
	return false;
}

void solve()
{
	int n;
	cin >> n;
	A.resize(n);
	map<int, int> M;
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
		M[A[i]]++;
	}
	// db(0 ^ 0);
	// db(25 ^ 0);
	if (M.size() == 1)
	{
		int a = M.begin()->f;
		if (a == 0)
		{
			cout << "Yes";
		}
		else
			cout << "No";
		return;
	}
	if (M.size() == 2)
	{
		int a = M.begin()->f;
		int b = (++M.begin())->f;
		int ac = M.begin()->s;
		int bc = (++M.begin())->s;
		if (a == 0)
			if (make(ac, bc) || make(bc, ac))
			{
				cout << "Yes";
				return;
			}
		cout << "No";
		return;
	}
	if (M.size() == 3)
	{
		db("here");
		ll a = M.begin()->f;
		ll b = (++M.begin())->f;
		ll c = (++(++M.begin()))->f;
		ll ac = M.begin()->s;
		ll bc = (++M.begin())->s;
		ll cc = (++(++M.begin()))->s;
		// auto m1 = M;
		int x = n / 3, y = n / 3, z = n / 3;
		if (n % 3 == 1)
		{
			++x;
		}
		if (n % 3 == 2)
		{
			++x;
			++y;
		}
		db(a, b, c, ac, bc, cc, x, y, z);
		if ((a ^ c) == b)
		{
			if (ac == x && bc == y && cc == z)
			{
				cout << "Yes";
				return;
			}
			if (ac == z && bc == y && cc == x)
			{
				cout << "Yes";
				return;
			}
			if (ac == x && bc == z && cc == y)
			{
				cout << "Yes";
				return;
			}
			if (ac == z && bc == x && cc == y)
			{
				cout << "Yes";
				return;
			}
			if (ac == y && bc == x && cc == z)
			{
				cout << "Yes";
				return;
			}
			if (ac == y && bc == z && cc == x)
			{
				cout << "Yes";
				return;
			}
		}
		cout << "No";
	}
	else
	{
		cout << "No";
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
#ifdef TIME
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}