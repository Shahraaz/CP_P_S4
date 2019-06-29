bool cmp(vector<int> &a, vector<int> &b)
{
	if (a[0] == b[0])
	{
		if (a[1] == b[1])
		{
			return a[2] < b[2];
		}
		return a[1] < b[1];
	}
	return a[0] < b[0];
}
vector<int> parent(4e4), Size(4e4);

void init()
{
	for (int i = 0; i < 4e4; ++i)
	{
		parent[i] = i;
		Size[i] = 1;
	}
}

int find(int i)
{
	if (parent[i] == i)
		return i;
	return parent[i] = find(parent[i]);
}

int Union(int a, int b)
{
	int o = find(a), t = find(b);
	if (o != t)
	{
		if (Size[o] < Size[t])
			swap(o, t);
		Size[o] += Size[t];
		parent[t] = o;
		return 1;
	}
	return 0;
}

class Solution
{
public:
	int earliestAcq(vector<vector<int>> &logs, int N)
	{
		init();
		sort(logs.begin(), logs.end());
		int m = N;
		for (int i = 0; i < logs.size(); ++i)
		{
			if (Union(logs[i][1], logs[i][2]))
				m--;
			//    cout << m << '\n';
			if (m == 1)
				return logs[i][0];
		}
		return -1;
	}
};