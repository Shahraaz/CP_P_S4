class Solution
{
	map<string, int> M;
	int n, m;
	vector<int> people;
	int dp[1 << 17][61];
	int pad[1 << 17][61];
	int solve(int mask, int i)
	{
		//cout << i << ' ' << __builtin_popcount(mask) << '\n';
		if (i == n)
		{
			if (__builtin_popcount(mask) == m)
				return 0;
			return 1e5;
		}
		int &ret = dp[mask][i];
		//cout << ret << '\n';
		if (ret >= 0)
			return ret;
		ret = solve(mask, i + 1);
		int nMask = mask;
		nMask |= people[i];
		int t = 1 + solve(nMask, i + 1);
		if (t < ret)
		{
			ret = t;
			pad[mask][i] = nMask;
		}
		else
			pad[mask][i] = mask;
		return ret;
	}
	vector<int> temp;
	void gen(int mask, int i)
	{
		if (i == n)
			return;
		if (mask != pad[mask][i])
			temp.push_back(i);
		gen(pad[mask][i], i + 1);
	}

public:
	vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &peoples)
	{
		n = peoples.size();
		m = req_skills.size();
		people.resize(peoples.size());
		for (int i = 0; i < req_skills.size(); ++i)
			M[req_skills[i]] = i + 1;
		for (int i = 0; i < n; ++i)
		{
			for (auto str : peoples[i])
			{
				int t = M[str];
				if (M[str] == 0)
					continue;
				--t;
				people[i] |= (1 << t);
			}
		}
		memset(dp, -1, sizeof(dp));
		memset(pad, 0, sizeof(pad));
		cout << solve(0, 0) << '\n';
		gen(0, 0);
		return temp;
	}
};