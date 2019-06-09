class Solution
{
public:
	int numTilePossibilities(string tiles)
	{
		set<string> s;
		int m = 1 << tiles.length();
		sort(tiles.begin(), tiles.end());
		while (m--)
		{
			string s1 = "";
			for (int i = 0; i < tiles.length(); ++i)
				if (m & (1 << i))
					s1.push_back(tiles[i]);
			do
			{
				if (s1 != "")
					s.insert(s1);
			} while (next_permutation(s1.begin(), s1.end()));
		}
		return s.size();
	}
};