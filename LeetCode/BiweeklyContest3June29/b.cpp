class Solution
{
public:
	int numKLenSubstrNoRepeats(string S, int K)
	{
		int n = S.size();
		if (n < K)
			return 0;
		map<char, int> Map;
		for (int i = 0; i < K; ++i)
			Map[S[i]]++;
		int ans = Map.size() == K;
		for (int i = K; i < n; ++i)
		{
			Map[S[i - K]]--;
			if (Map[S[i - K]] == 0)
			{
				Map.erase(S[i - K]);
			}
			Map[S[i]]++;
			ans += Map.size() == K;
		}
		return ans;
	}
};