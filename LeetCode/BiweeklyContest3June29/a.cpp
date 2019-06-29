class Solution
{
public:
	int twoSumLessThanK(vector<int> &A, int K)
	{
		int n = A.size();
		int s = -1;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
			{
				int temp = A[i] + A[j];
				if (temp < K)
					s = max(s, temp);
			}
		return s;
	}
};