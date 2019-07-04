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
const long long mod = 1000000007;

ll power(ll base, int index)
{
	if (index == 0)
		return 1;
	ll temp = power(base, index / 2);
	temp *= temp;
	temp %= mod;
	if (index & 1)
		temp *= base;
	return temp % mod;
}

class Strawberry
{
private:
	int n, k;
	vector<ll> ProbA, ProbB;
	vector<ll> GetProb(vector<int> A)
	{
		int n = A.size();
		vector<ll> temp(n);
		ll sum = 0;
		for (int i = 0; i < n; ++i)
			sum += A[i];
		if (sum == 0)
			return temp;
		ll inv = power(sum, mod - 2);
		for (int i = 0; i < n; ++i)
			temp[i] = (A[i] * inv) % mod;
		return temp;
	}
	map<pair<int, int>, ll> Dp;
	ll solve(int turn, int currDiff)
	{
		if (turn == n + 1)
			return 1;
		auto it = Dp.find({turn, currDiff});
		if (it != Dp.end())
			return it->s;
		auto &ret = Dp[{turn, currDiff}];
		int nextDiff;
		if (turn & 1)
		{
			for (int i = 0; i < ProbA.size(); ++i)
			{
				nextDiff = i - currDiff;
				if (abs(nextDiff) <= k)
				{
					ret += ProbA[i] * solve(turn + 1, nextDiff);
					ret %= mod;
				}
			}
		}
		else
		{
			for (int i = 0; i < ProbB.size(); ++i)
			{
				nextDiff = i - currDiff;
				if (abs(nextDiff) <= k)
				{
					ret += ProbB[i] * solve(turn + 1, nextDiff);
					ret %= mod;
				}
			}
		}
		return ret;
	}

public:
	int competitive(int n, int k, vector<int> A, vector<int> B)
	{
		ProbA = GetProb(A);
		ProbB = GetProb(B);
		this->n = n;
		this->k = k;
		return solve(1, 0);
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