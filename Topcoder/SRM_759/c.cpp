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

ll kmod = 1000000000000037;
class EllysHash
{
	vector<string> T;
	int n;
	vector<ll> ValuesUptoHalf;
	ll answer = kmod - 1;
	void leftHalfSolver(int index, ll hashUpToHere)
	{
		if (index == n / 2)
		{
			for (; index < n; ++index)
				hashUpToHere = (hashUpToHere * 127) % kmod;
			ValuesUptoHalf.pb(hashUpToHere);
			return;
		}
		for (int i = 0; i < 3; ++i)
			leftHalfSolver(index + 1, (hashUpToHere * 127 + T[i][index]) % kmod);
	}
	void rightHalfSolver(int index, ll hashUpToHere)
	{
		if (index == n)
		{
			index = lower_bound(ValuesUptoHalf.begin(), ValuesUptoHalf.end(), kmod - hashUpToHere) - ValuesUptoHalf.begin();
			index %= ValuesUptoHalf.size();
			answer = min(answer, (hashUpToHere + ValuesUptoHalf[index]) % kmod);
			return;
		}
		for (int i = 0; i < 3; ++i)
			rightHalfSolver(index + 1, (hashUpToHere * 127 + T[i][index]) % kmod);
	}

public:
	long long getHash(int N, string A, string B, string C)
	{
		n = N;
		T.pb(A);
		T.pb(B);
		T.pb(C);
		leftHalfSolver(0, 0);
		sort(ValuesUptoHalf.begin(), ValuesUptoHalf.end());
		ValuesUptoHalf.erase(unique(ValuesUptoHalf.begin(), ValuesUptoHalf.end()), ValuesUptoHalf.end());
		rightHalfSolver(n / 2, 0);
		return answer;
	}
};