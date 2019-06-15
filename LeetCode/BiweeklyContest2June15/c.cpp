class Solution
{
public:
	vector<string> res;
	void dfs(string &s, int index, string prev)
	{
		if (s[index] == '\0')
		{
			res.push_back(prev);
			return;
		}
		if (s[index] == '{')
		{
			vector<char> Child;
			int j;
			for (j = index + 1; s[j] != '}'; ++j)
			{
				if (s[j] == ',')
					continue;
				Child.push_back(s[j]);
			}
			sort(Child.begin(), Child.end());
			for (auto ch : Child)
				dfs(s, j + 1, prev + ch);
		}
		else
			dfs(s, index + 1, prev + s[index]);
	}
	vector<string> permute(string S)
	{
		dfs(S, 0, "");
		return res;
	}
};