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

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef map<pipii, int> cache;

class StripePainter
{
private:
	/* data */
public:
	string stripes;
	int n;
	cache ch;
	int solve(int start, int end, char b)
	{
		while (start < end && stripes[start] == b)
			++start;
		while (start < end && stripes[end - 1] == b)
			--end;
		if (start == end)
			return 0;
		if (start + 1 == end)
			return 1;
		auto it = ch.find({start, {end, b}});
		if (it != ch.end())
			return *it;
		int &r = ch[{start, {end, b}}];
		r = 1000;
		for (int j = start + 1; j < end; ++j)
			r = min(r, solve(start, j) + solve(j, end));
		for (char j = 'A'; j <= 'Z'; ++j)
			r = min(r, solve(start, end, j));
		return r;
	}

	int minStrokes(string stripes)
	{
		this->stripes = stripes;
		n = stripes.length();
		return solve(0, n, ' ');
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