//Optimise
#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
#define pb push_back
typedef long long ll;
vector<int> V;

int A, B, C;
ll DFS(int curr, int a, int b, int c)
{
	if (curr == V.size())
	{
		if(a>0 && b>0 && c>0)
		return abs(a - A) + abs(b - B) + abs(c - C) - 30;
		else return 1e16;
	}
	ll temp = DFS(curr + 1, a, b, c);
	temp = min(temp, DFS(curr + 1, a + V[curr], b, c) + 10);
	temp = min(temp, DFS(curr + 1, a, b + V[curr], c) + 10);
	temp = min(temp, DFS(curr + 1, a, b, c + V[curr]) + 10);
	return temp;
}

void solve()
{
	int n;
	cin >> n >> A >> B >> C;
	V.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> V[i];
	cout << DFS(0, 0, 0, 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}
