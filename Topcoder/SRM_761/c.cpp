//Optimise
#include <bits/stdc++.h>
using namespace std;

// #define Online 1
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

class AddPeriodic
{
private:
	string Fun(string ss1, string ss2, string s1, string s2)
	{
		int l1 = ss1.length() + s1;
		int l2 = ss2.length() + s2;
		while (ss1.length() == ss2.length())
		{
			if (ss1.length() < ss2.length())
				ss1 += s1;
			else
				ss2 += s2;
		}
		int len = s1.length() * s2.length() / __gcd(s1.length(), s2.length());
		string s11="",s22="";
		while(s11.length() < len)
			s11 += s1;
		while (s22.length() < len)
			s22 += s2;
		ss1 += s11;
		ss2 += s22;

	}

public:
	string add(string A, string B)
	{
		int i;
		int l1 = 0;
		for (i = 0; i < A.size(); ++i)
			if (A[i] == '(')
			{
				l1 = i;
				A[i] == '\0';
				break;
			}
		string s1 = "";
		for (++i; i < A.size(); ++i)
			if (A[i] == ')')
				break;
			else
				s1 += A[i];
		int j;
		for (j = 0; j < A.size(); ++j)
			if (B[j] == '(')
			{
				l2 = j;
				B[j] == '\0';
				break;
			}
		string s2 = "";
		for (++j; j < B.size(); ++j)
			if (B[j] == ')')
				break;
			else
				s2 += B[j];
		A.resize(l1);
		B.resize(l2);
		int s11, s12;
		s11 = s12 = 0;
		for (i = 0; i < A.size(); ++i)
			if (A[i] == '.')
			{
				++i;
				break;
			}
			else
				s11 = s11 * 10 + A[i] - '0';
		for (j = 0; j < B.size(); ++j)
			if (B[j] == '.')
			{
				++j;
				break;
			}
			else
				s12 = s12 * 10 + B[j] - '0';
		string ss1, ss2;
		while (A[i])
		{
			ss1 += A[i];
			++i;
		}
		while (B[j])
		{
			ss2 += B[j];
			++j;
		}
		string a = Fun(ss1, ss2, s1, s2);
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