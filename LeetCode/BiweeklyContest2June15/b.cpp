class Solution
{
public:
	vector<vector<int>> highFive(vector<vector<int>> &items)
	{
		map<int, multiset<int>> Score;
		map<int, int> Count;
		for (auto x : items)
		{
			Score[x[0]].insert(x[1]);
			Count[x[0]]++;
			if (Count[x[0]] == 6)
			{
				Count[x[0]]--;
				Score[x[0]].erase(Score[x[0]].begin());
			}
		}
		vector<vector<int>> Ret;
		for (auto it = Score.begin(); it != Score.end(); ++it)
		{
			Ret.push_back(vector<int>(1, it->first));
			int sum = 0;
			for (auto it2 = Score[it->first].begin(); it2 != Score[it->first].end(); ++it2)
				sum += *it2;
			Ret.back().push_back(sum / Count[it->first]);
		}
		return Ret;
	}
};