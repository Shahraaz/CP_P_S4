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

class ConnectTheCities
{
private:
	int distance, n, key;
	vector<int> position;
	int f[110][110];
	int solve(int v, int l)
	{
		if (v == n)
			return (abs(l - distance) <= key) ? 0 : 1e9;
		int &ret = f[v][l];
		if (ret >= 0)
			return ret;
		ret = 1e9;
		for (int i = l; i <= distance; ++i)
			if (abs(i - l) <= key)
				ret = min(ret, solve(v + 1, i) + abs(i - position[v]));
		return ret;
	}
public:
	int minimalRange(int distance, int funds, vector<int> position)
	{
		this->distance = distance;
		this->n = position.size();
		sort(position.begin(), position.end());
		this->position = position;
		int low = -1, high = 110;
		while (low + 1 < high)
		{
			key = (low + high) / 2;
			memset(f, -1, sizeof(f));
			int rd = solve(0, 0);
			if (rd <= funds)
				high = key;
			else
				low = key;
		}
		return high;
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