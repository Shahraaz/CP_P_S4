class Solution
{
public:
	vector<string> findOcurrences(string text, string first, string second)
	{
		vector<string> answer;
		first += " " + second + " ";
		size_t nPos = text.find(first, 0); // first occurrence
		while (nPos != string::npos)
		{
			int t = nPos + first.length();
			string s = "";
			for (; text[t] >= 'a' && text[t] <= 'z'; ++t)
				s.push_back(text[t]);
			nPos = text.find(first, nPos + 1);
			answer.push_back(s);
		}
		return answer;
	}
};