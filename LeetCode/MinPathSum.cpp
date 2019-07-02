class Solution
{
public:
	int minPathSum(vector<vector<int>> &grid)
	{
		int n, m;
		n = grid.size();
		m = grid[0].size();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				//cout << i << ' ' << j << '\n';
				if (i == 0 && j == 0)
					continue;
				if (i == 0)
					grid[i][j] += grid[i][j - 1];
				else if (j == 0)
					grid[i][j] += grid[i - 1][j];
				else
					grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
			}
		return grid[n - 1][m - 1];
	}
};