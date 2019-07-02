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

vector<vector<int>> len(50,vector<int>(50));
vector<vector<int>> pad(50, vector<int>(50));

class ShortPalindromes
{
private:
	/* data */
public:
	string shortest(string base)
	{
		string ans = "";
		int n = base.size();
		for (int i = 0; i < n; ++i)
		{
			len[i][i] = 1;
			len[i + 1][i] = 0;
			pad[i][i] = 4;
			pad[i + 1][i] = 4;
		}
		for (int l = 2; l <= n; ++l)
			for (int i = 0; i <= n - l; ++i)
			{
				int j = i + l - 1;
				char h, t;
				h = base[i];
				t = base[j];
				if (h == t)
				{
					len[i][j] = len[i + 1][j - 1] + 2;
					pad[i][j] = 3;
				}
				else
				{
					if (len[i + 1][j] < len[i][j - 1])
					{
						len[i][j] = len[i + 1][j] + 2;
						pad[i][j] = 1;
					}
					else if (len[i + 1][j] > len[i][j - 1])
					{
						len[i][j] = len[i][j - 1] + 2;
						pad[i][j] = 2;
					}
					else
					{
						if (h < t)
						{
							len[i][j] = len[i + 1][j] + 2;
							pad[i][j] = 1;
						}
						else
						{
							len[i][j] = len[i][j - 1] + 2;
							pad[i][j] = 2;
						}
					}
				}
			}
		int i, j, l;
		i = 0;
		j = n - 1;
		l = 0;
		while (i < j)
		{
			switch (pad[i][j])
			{
			case 1:
				ans = ans + base[i];
				++i;
				l++;
				break;

			case 2:
				ans = ans + base[j];
				--j;
				l++;
				break;

			case 3:
				ans = ans + base[i];
				++i;
				--j;
				l++;
				break;

			default:
				break;
			}
		}
		if (i == j)
			ans += base[i];
		for (int i = l - 1; i >= 0; --i)
			ans += ans[i];
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