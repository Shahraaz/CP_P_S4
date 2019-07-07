class Solution
{
	vector<int> res;
	string seq;
	void solve(int start, int end, int virtualDepth)
	{
		//cout << start << ' ' << end << ' ' << virtualDepth << '\n';
		if (start > end)
			return;
		if (start == end)
			return;
		int cnt = seq[start] == '(', prev = start;
		for (int i = start + 1; i <= end; ++i)
		{
			//  cout << i << '\n';
			if (seq[i] == '(')
				cnt++;
			else
				cnt--;
			//cout << "Here ";
			//cout << i << '\n';
			if (cnt == 0)
			{
				res[prev] = (virtualDepth & 1);
				res[i] = (virtualDepth & 1);
				//  cout << "Prev " << prev << " i " << i << '\n';
				solve(prev + 1, i - 1, virtualDepth + 1);
				prev = i + 1;
			}
			//cout << i << ' ' << "End " << cnt << '\n';
		}
	}

public:
	vector<int> maxDepthAfterSplit(string seq)
	{
		this->seq = seq;
		res.resize(seq.size());
		solve(0, seq.size() - 1, 1);
		return res;
	}
};