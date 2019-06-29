typedef pair<int, int> pii;
cont int N = 110;
bool flag[N][N];
const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution
{
public:
	int n, m;
	vector<vector<int>> A;
	bool isvalid(int i, int j)
	{
		return i >= 0 && i < n && j >= 0 && j < m;
	}
	bool check(int limit)
	{
		if (A[0][0] < limit || A[n - 1][m - 1] < limit)
			return false;
		memset(flag, 0, sizeof(flag));
		queue<pair<int, int>> Q;
		flag[0][0] = true;
		while (!Q.empty())
		{
			int x = Q.front().f, y = Q.front().s;
			Q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int i1 = x + d[i][0];
				int j1 = y + d[i][1];
				if (isvalid(i1, j1) && !flag[i1][j1] && A[i1][j1] >= limit)
					Q.push({i1, j1});
			}
		}
		return flag[n - 1][m - 1];
	}
	int maximumMinimumPath(vector<vector<int>> &A)
	{
		this->A = A;
		n = A.size();
		m = A[0].size();
		int low = 0, high = 1e9;
		while (low != high)
		{
			int mid = (low + high) / 2;
			if (check(mid))
				low = mid;
			else
				high = mid + 1;
		}
		return low;
	}
};