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

class FlowerGarden
{
private:
	/* data */
public:
	vector<int> getOrdering(vector<int> height, vector<int> bloom, vector<int> wilt)
	{
		int n = height.size();
		vector<bool> Done(n);
		vector<int> ret(n);
		for (int i = 0; i < n; ++i)
		{
			int best = -1;
			for (int j = 0; j < n; ++j)
				if (!Done[j])
				{
					bool ok = true;
					for (int k = 0; k < n; ++k)
						if (!Done[k] && j != k && height[k] < height[j] && bloom[k] <= wilt[j] && bloom[j] <= wilt[k])
							ok = false;
					if (ok && (best == -1 || height[j] > height[best]))
						best = j;
				}
			ret[i] = height[best];
			Done[best] = true;
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