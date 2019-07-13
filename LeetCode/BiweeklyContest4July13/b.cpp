class Solution
{
public:
	string removeVowels(string S)
	{
		string s;
		for (auto c : S)
		{
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				continue;
			s += c;
		}
		return s;
	}
};