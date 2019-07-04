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

void add_self(int &a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
}

template <typename T>
T mul(T &a, int b)
{
	return (ll)a * b % mod;
}

struct Matrix
{
	int n;
	vector<vector<int>> t;
	Matrix(int n = 50)
	{
		this->n = n;
		t.resize(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
			t[i][i] = 1;
	}
	Matrix operator*(const Matrix &b) const
	{
		Matrix c = Matrix(n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				c.t[i][j] = 0;
				for (int k = 0; k < n; ++k)
					add_self(c.t[i][j], mul(t[i][k], b.t[k][j]));
			}
		return c;
	}
};

Matrix power(Matrix &a, ll index)
{
	if (index == 0)
		return Matrix(a.n);
	Matrix temp = power(a, index / 2);
	temp = temp * temp;
	if (index & 1)
		temp = temp * a;
	return temp;
}

void solve()
{
	ll n, k;
	cin >> n >> k;
	vector<vector<int>> Can(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> Can[i][j];
	Matrix answer = Matrix(n);

	Matrix cani(n);
	cani.t = Can;
	answer = power(cani, k);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			db(i, j, answer.t[i][j]);
			add_self(ans, answer.t[i][j]);
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