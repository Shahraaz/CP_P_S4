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

class Graduation
{
private:
	vector<bool> taken;
	vector<vector<int>> M;
	int bpm(int nm = 128)
	{
		vector<int> mat(nm, -1), res(M.size(), -1);
		int i, j, x, y, ret = 0;
		for (i = 0; i < M.size(); ++i)
		{
			queue<int> Q;
			vector<int> pred(M.size(), -1);
			Q.push(i);
			pred[i] = -2;
			while (!Q.empty())
			{
				x = Q.front();
				Q.pop();
				for (j = 0; j < M[x].size(); ++j)
					if (taken[M[x][j]])
					{
						y = mat[M[x][j]];
						if (y == -1)
							goto found;
						if (pred[y] != -1)
							continue;
						pred[y] = x;
						Q.push(y);
					}
			}
			continue;
		found:
			y = M[x][j];
			ret++;
			while (x != -2)
			{
				mat[y] = x;
				swap(res[x], y);
				x = pred[x];
			}
		}
		return ret;
	}

public:
	string moreClasses(string classesTaken, vector<string> requirements)
	{
		taken.resize(128);
		int x, z, n;
		string ret = "";
		for (auto b : requirements)
		{
			n = atoi(b.c_str());
			for (int i = 0; i < n; ++i)
			{
				M.pb(vector<int>());
				for (int k = 0; k < b.size(); ++k)
					if (!isdigit(b[k]))
						M.back().pb(b[k]);
			}
		}
		if (M.size() > 128)
			return "0";
		for (auto c : classesTaken)
			taken[c] = true;
		n = M.size() - bpm();
		x = 33;
		while (n)
		{
			if (x >= 128)
				return "0";
			if (taken[x])
			{
				x++;
				continue;
			}
			taken[x] = true;
			z = M.size() - bpm();
			if (z == n)
				taken[x] = false;
			else
				ret += x;
			n = z;
			x++;
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
	Graduation S;
	// while (t--)
	// 	S.Graduation();
	return 0;
}
#endif