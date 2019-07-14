class Solution
{
public:
	int longestWPI(vector<int> &hours)
	{
		int prev = 0;
		int i = 0;
		for (int &x : hours)
		{
			if (x > 8)
				x = 1;
			else
				x = -1;
		}
		int len = 0;
		int n = hours.size();
		vector<int> sums(n + 1);
		for (int i = 0; i < n; ++i)
			sums[i + 1] = sums[i] + hours[i];
		for (int i = 0; i < n; ++i)
			for (int j = n; j > i && j - i > len; --j)
				if (sums[i] < sums[j])
					len = j - i;
		return len;
	}
};