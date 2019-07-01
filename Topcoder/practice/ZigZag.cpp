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

class ZigZag
{
private:
	/* data */
public:
	vector<int> sequence;
	int n;
	vector<vector<int>> Dp;
	int recurse(int idx, int diff)
	{
		if (idx == n)
			return 0;
		if (diff == 0)
			return 0;
		if (diff < 0)
			diff = 0;
		else
			diff = 1;
		if (Dp[idx][diff] >= 0)
			return Dp[idx][diff];
		int ans = 1;
		for (int j = idx + 1; j < n; ++j)
			if (diff)
			{
				if (sequence[idx] < sequence[j])
					ans = max(ans, 1 + recurse(j, -1));
			}
			else
			{
				if (sequence[idx] > sequence[j])
					ans = max(ans, 1 + recurse(j, 1));
			}
		return Dp[idx][diff] = ans;
	}
	int longestZigZag(vector<int> sequence)
	{
		int n = sequence.size();
		this->sequence = sequence;
		this->n = n;
		this->Dp = vector<vector<int>>(n, vector<int>(50, -1));
		int ans = 1;
		for (int i = 0; i < n; ++i)
		{
			ans = max(ans, recurse(i, 1));
			ans = max(ans, recurse(i, -1));
		}
		return ans;
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