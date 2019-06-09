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

ll power(int base, int index)
{
	if (index == 0)
		return 1;
	ll temp = power(base, index / 2);
	temp = (temp * temp) % mod;
	if (index & 1)
		temp *= base;
	return temp % mod;
}

string l;
ll solve(int index, int length)
{
	if (length == 1)
	{
		if (index >= l.length())
		{
			cout << "Wrong";
			exit(0);
		}
		if (l[index] == '0')
			return 1;
		else
			return 3;
	}
	ll answer = 0;
	if (l[index] == '1')
		answer += power(3, length - 1);
	answer %= mod;
	if (l[index] == '1')
		answer = (answer + 2 * solve(index + 1, length - 1)) % mod;
	else
		answer = (answer + solve(index + 1, length - 1)) % mod;
	// db(length, answer);
	return answer;
}

void solve()
{
	cin >> l;
	// int n = 0;
	// for (char c : l)
	// 	n = n * 2 + (c - '0');
	// int cnt = 0;
	// for (int i = 0; i <= n; ++i)
	// 	for (int j = 0; j <= n; ++j)
	// 	{
	// 		if (i + j <= n)
	// 		{
	// 			if ((i + j) == (i ^ j))
	// 			{
	// 				cnt++;
	// 				cout << i << ' ' << j << '\n';
	// 			}
	// 		}
	// 	}
	// cout << cnt << '\n';
	cout << solve(0, l.length()) << '\n';
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