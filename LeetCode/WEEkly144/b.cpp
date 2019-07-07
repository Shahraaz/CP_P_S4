class Solution
{
public:
	vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
	{
		int n = bookings.size();
		vector<int> V;
		for (int i = 0; i < n; ++i)
		{
			int start = bookings[i][0];
			int end = bookings[i][1];
			if ((end + 1) > V.size())
				V.resize(end + 1);
			V[strart - 1] += bookings[i][2];
			V[end] -= bookings[i][2];
		}
		V.pop_back();
		for (int i = 1; i < V.size(); ++i)
		{
			V[i] += V[i - 1];
		}
		return V;
	}
};