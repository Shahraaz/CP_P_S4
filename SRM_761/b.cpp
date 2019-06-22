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

int a[4] = {0, 0, 1, -1};
int b[4] = {1, -1, 0, 0};
class Pickaxe
{
private:
	vector<string> Mat;
	int n, m;
	bool isvalid(int a, int b)
	{
		return a < n && a >= 0 && b < m && b >= 0;
	}
	bool Bfs()
	{
		queue<pair<int, int>> Q;
		vector<vector<bool>> Vis(n, vector<bool>(m, false));
		Q.push({0, 0});
		Vis[0][0] = true;
		while (!Q.empty())
		{
			auto t = Q.front();
			Q.pop();
			if (t.f == (n - 1) && t.s == (m - 1))
				return true;
			for (int i = 0; i < 4; ++i)
			{
				int u = t.f + a[i], v = t.s + b[i];
				if (isvalid(u, v) && !Vis[u][v] && Mat[u][v] == '.')
				{
					Vis[u][v] = true;
					Q.push({u, v});
				}
			}
			return false;
		}
	}

public:
	int countWalls(vector<string> maze)
	{
		int ret = 0;
		Mat = maze;
		n = Mat.size();
		m = Mat[0].size();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				if (Mat[i][j] == '#')
				{
					Mat[i][j] = '.';
					ret += Bfs();
					Mat[i][j] = '#';
				}
			}
		return ret;
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