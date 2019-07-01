//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Online 1
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
const long long mod = 1234567891;

class TheCardLineDivTwo
{
private:
	vector<string> cards;
	vector<vector<int>> cache;
	int n;
	bool clr(char c)
	{
		switch (c)
		{
		case 'H':
			return 1;
			break;

		case 'D':
			return 1;
			break;

		default:
			return 0;
			break;
		}
		return 0;
	}
	bool compatible(int card1, int card2)
	{
		return (cards[card1][0] == cards[card2][0]) || (clr(cards[card2][1]) == clr(cards[card1][1]));
	}
	int recurse(int last, int valid)
	{
		if (cache[last][valid] != -1)
			return cache[last][valid];
		if (valid == 0)
			return cache[last][0] = 1;
		ll ans = 0;
		for (int i = 0; i < n; ++i)
			if (valid & (1 << i))
				if (compatible(last, i))
					ans = (ans + recurse(i, valid ^ (1 << i))) % mod;
		return cache[last][valid] = ans;
	}

public:
	int count(vector<string> cards)
	{
		int n = cards.size();
		this->cards = cards;
		this->n = n;
		cache = vector<vector<int>>(n, vector<int>(1 << n, -1));
		ll ans = 0, all = (1 << n) - 1;
		for (int i = 0; i < n; ++i)
			ans = (ans + recurse(i, all ^ (1 << i))) % mod;
		return (int)ans;
	}
};

#ifndef Online
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	Solver S;
	while (t--)
		S.Solve();
	return 0;
}
#endif