class Solution
{
public:
	int sumOfDigits(vector<int> &A)
	{
		int min = *min_element(A.begin(), A.end());
		int cnt = 0;
		while (min)
		{
			cnt += min % 10;
			min /= 10;
		}
		return !(cnt & 1);
	}
};