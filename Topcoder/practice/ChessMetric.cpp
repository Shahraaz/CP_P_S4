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

int a[16] = {-2, -2, -1, -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 1, 2, 2};
int b[16] = {1, -1, -2, -1, 0, 1, 2, 1, -1, -2, -1, 0, 1, 2, 1, -1};

class ChessMetric
{
private:
	/* data */
public:
	int size = 0;
	bool valid(int i, int j)
	{
		return i >= 0 && i < size && j >= 0 && j < size;
	}
	long howMany(int size, vector<int> start, vector<int> end, int numMoves)
	{
		vector<vector<vector<ll>>> Dp(numMoves + 1, vector<vector<ll>>(size, vector<ll>(size)));
		this->size = size;
		Dp[0][start[0]][start[1]] = 1;
		for (int i = 1; i <= numMoves; ++i)
			for (int x = 0; x < size; ++x)
				for (int y = 0; y < size; ++y)
					for (int a1 = 0; a1 < 16; ++a1)
					{
						int x1 = x + a[a1];
						int y1 = y + b[a1];
						if (valid(x1, y1))
							Dp[i][x][y] += Dp[i - 1][x1][y1];
					}
		return Dp[numMoves][end[0]][end[1]];
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