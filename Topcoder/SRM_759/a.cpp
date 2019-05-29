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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class EllysViewPoints
{
public:
	int getCount(int N, int M, vector<string> matrix)
	{
		int ans = 0;
		vector<bool> clrrow(N),clrcol(M);
		for(int i=0;i<N;++i)
		{
			clrrow[i] = true;
			for(int j=0;j<M;++j)
			{
				if(matrix[i][j]=='#')
				{
					clrrow[i] = false;
					break;
				}
			}
		}
		for(int i=0;i<M;++i)
		{
			clrcol[i] = true;
			for(int j=0;j<N;++j)
			{
				if(matrix[j][i]=='#')
				{
					clrcol[i] = false;
					break;
				}
			}
		}
		for(int i=0;i<N;++i)
			if(clrrow[i])
			for(int j=0;j<M;++j)
				if(clrcol[j]) ans++;
		return ans;
	}
};