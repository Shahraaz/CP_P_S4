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

const int MAX = 1e6 + 5;
typedef long long ll;
vector<ll> sieve;
ll pf[MAX];
void construct_sieve()
{
    for(int i = 0;i < MAX;i++) pf[i] = i;
    for (ll i = 2;i * i<=MAX;i++)
    {
        if (pf[i] == i)
        {
            for (ll j = 2;j * i<MAX;j++) if (pf[i*j] == i*j)pf[i*j] = i;
        }
    }

    for (ll i = 2;i<MAX;i++)
    if (pf[i] == i && i>=11111 && i <= 99999)sieve.push_back(i);
}

bool cond(int r4, int r3, int r2, int r1, int r0)
{
	return (r4 >= 0 && r4 <= 9 && r3 >= 0 && r3 <= 9 && r2 >= 0 && r2 <= 9 && r1 >= 0 && r1 <= 9 && r0 >= 0 && r0 <= 9);
}

class EllysThreePrimes
{
public:
	vector<int> getPrimes(vector<int> sums)
	{
		reverse(sums.begin(), sums.end());
		construct_sieve();
		int sz = sieve.size();
		for (int i = 0; i < sz; i++)
		{
			int first = sieve[i];
			int a0 = first % 10;
			first /= 10;
			int a1 = first % 10;
			first /= 10;
			int a2 = first % 10;
			first /= 10;
			int a3 = first % 10;
			first /= 10;
			int a4 = first % 10;
			//cout << "a: " << a4 << a3 << a2 << a1 << a0 << endl;
			for (int j = i + 1; j < sz; j++)
			{
				first = sieve[j];
				int b0 = first % 10;
				first /= 10;
				int b1 = first % 10;
				first /= 10;
				int b2 = first % 10;
				first /= 10;
				int b3 = first % 10;
				first /= 10;
				int b4 = first % 10;
				//cout << "b: "<< b4 << b3 << b2 << b1 << b0 << endl;
				int r0 = sums[0] - a0 - b0;
				int r1 = sums[1] - a1 - b1;
				int r2 = sums[2] - a2 - b2;
				int r3 = sums[3] - a3 - b3;
				int r4 = sums[4] - a4 - b4;
				//cout << "r: " << r4 << r3 << r2 << r1 << r0 << endl;
				if (cond(r4, r3, r2, r1, r0))
				{
					int numb = 10000 * r4 + 1000 * r3 + 100 * r2 + 10 * r1 + r0;
					if (numb >= 11111 && numb <= 99999 && pf[numb] == numb && numb != sieve[i] && numb != sieve[j])
					{
						vector<int> v;
						v.pb(sieve[i]);
						v.pb(sieve[j]);
						v.pb(numb);
						return v;
					}
				}
			}
		}
		vector<int> v;
		return v;
	}
};