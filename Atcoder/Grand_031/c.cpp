//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Online 1
// #define multitest 1
typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;
const long long High = 1e16;
void ControlIO();
void TimerStart();
void TimerStop();
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__)
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

bool isPowerOfTwo(unsigned int x)
{
	// First x in the below expression is
	// for the case when x is 0
	return x && (!(x & (x - 1)));
}

// function to check whether the two numbers
// differ at one bit position only
bool differAtOneBitPos(unsigned int a, unsigned int b)
{
	return isPowerOfTwo(a ^ b);
}
vector<string> arr;

void generateGrayarr(int n)
{
	// base case
	if (n <= 0)
		return;

	// 'arr' will store all generated codes

	// start with one-bit pattern
	arr.push_back("0");
	arr.push_back("1");

	// Every iteration of this loop generates 2*i codes from previously
	// generated i codes.
	int i, j;
	for (i = 2; i < (1 << n); i = i << 1)
	{
		// Enter the prviously generated codes again in arr[] in reverse
		// order. Nor arr[] has double number of codes.
		for (j = i - 1; j >= 0; j--)
			arr.push_back(arr[j]);

		// append 0 to the first half
		for (j = 0; j < i; j++)
			arr[j] = "0" + arr[j];

		// append 1 to the second half
		for (j = i; j < 2 * i; j++)
			arr[j] = "1" + arr[j];
	}

	// print contents of arr[]
	// for (i = 0; i < arr.size(); i++)
	// 	cout << arr[i] << endl;
}

void solve()
{
	int n, a, b;
	cin >> n >> a >> b;
	if ((a & b == 0) || (differAtOneBitPos(a, b)))
	{
		cout << "YES\n";
		// generateGrayarr(n);
		if (a & b == 0)
		{
			generateGrayarr(n - 1);
			int t = arr.size();
			arr.push_back(arr[arr.size() - 1]);
			for (int i = 0; i < t - 1; ++i)
				arr.pb(arr[i]);
			int i = 0;
			for (i = 0; i < t; ++i)
				arr[i] = "0" + arr[i];
			for (; i < 2 * t; ++i)
				arr[i] = "1" + arr[i];
		}
		else
			generateGrayarr(n - 1);
		// string start = "",end = "";
		// while(a)
		
	}
	else
	{
		cout << "NO\n";
	}
}

int main()
{
	ControlIO();
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	TimerStart();
	while (t--)
		solve();
	TimerStop();
	return 0;
}

void ControlIO()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef Online
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();

void TimerStart()
{
#ifndef Online
	TimeStart = chrono::steady_clock::now();
#endif
}

void TimerStop()
{
#ifndef Online
	TimeEnd = chrono::steady_clock::now();
	auto ElapsedTime = TimeEnd - TimeStart;
	cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
#endif
}
