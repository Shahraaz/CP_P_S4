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

class QuickSums
{
private:
	/* data */
public:
	string number;
	int n;
	map<pair<pair<int, int>, int>, int> Cache;
	int solve(int start, int end, int sum)
	{
		if (sum < 0)
			return -1;
		if (start > end || start < 0 || start >= n || end < 0 || end >= n)
			return mod;
		if (start == end)
		{
			if (number[start] - '0' == sum)
				return 0;
			return -1;
		}
		auto it = Cache.find({{start, end}, sum});
		if (it != Cache.end())
			return it->s;
		auto &r = Cache[{{start, end}, sum}];
		int num = number[start] - '0';
		r = -1;
		for (int i = start + 1; i < end; ++i)
		{
			int temp = solve(i, end, sum - num);
			num = num * 10 + num[i] - '0';
			if (temp == -1)
				continue;
			if (r == -1)
				r = temp + 1;
			else
				r = min(r, temp + 1);
		}
		if (num == sum)
			r = 0;
		return r;
	}
	int minSums(string numbers, int sum)
	{
		n = numbers.size();
		number = numbers;
		return solve(0, n - 1, sum);
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