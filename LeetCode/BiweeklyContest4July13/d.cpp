class Solution
{
public:
	vector<deque<int>> Dq;
	bool canDivideIntoSubsequences(vector<int> &nums, int K)
	{
		int maxCnt = -1, start, end;
		for (auto it = nums.begin(); it < nums.end();)
		{
			auto up = upper_bound(it, nums.end(), *it);
			if (maxCnt < up - it)
			{
				int cnt = up - it;
				maxCnt = max(maxCnt, cnt);
				start = it - nums.begin();
				end = up - nums.begin();
			}
			it = up;
		}
		if (maxCnt > K)
			return false;
		Dq.resize(maxCnt);
		for (int i = 0; i < maxCnt; ++i)
			Dq[i].push_back(nums[start]);
		int idx = 0;
		for (int i = 0; i < start; ++i)
		{
			Dq[idx].push_front(nums[i]);
			idx = (idx + 1) % maxCnt;
		}
		for (int i = end; i < nums.size(); ++i)
		{
			Dq[idx].push_back(nums[i]);
			idx = (idx + 1) % maxCnt;
		}
		for (int i = 0; i < maxCnt; ++i)
		{
			if (Dq[i].size() < K)
				return false;
		}
		return true;
	}
};