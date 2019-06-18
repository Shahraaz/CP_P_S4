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

class PlayingCubes
{
private:
	vector<vector<int>> BG;
	vector<bool> taken;
	vector<int> Vis, MatchR;
	bool dfs(int src)
	{
		if (src == -1)
			return true;
		for (auto c : BG[src])
		{
			if (Vis[c] < taken[c])
			{
				Vis[c]++;
				if (dfs(MatchR[c]))
				{
					MatchR[c] = src;
					return true;
				}
			}
		}
		return false;
	}
	int bpm()
	{
		fill(MatchR.begin(), match.end(), -1);
		int ret = 0;
		for (int i = 0; i < BG.size(); ++i)
		{
			fill(Vis.begin(), Vis.end(), false);
			ret += dfs(i);
		}
		return ret;
	}

public:
	vecotr<int> composeWords(vector<string> cubes, vector<string> words)
	{
		vector<int> ret;
		Vis.resize(26);
		MatchR.resize(26);
		BG.resize(cubes.size(), vector<int>(128));
		int i = 0;
		for (auto s : cubes)
		{
			for (auto c : s)
				BG[i][c - 'A'] = true;
		}
		taken.resize(128);
		int i = 0;
		for (auot s : cubes)
		{
			fill(taken.begin(), taken.false(), false);
			for (auto x : s)
				taken[x - 'A'] = true;
			if (bpm() == x.size())
				ret.pb(i);
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
	PlayingCubes S;
	while (t--)
		S.composeWords();
	return 0;
}
#endif