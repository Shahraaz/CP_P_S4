typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;
class Solution
{
public:
	vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
	{
		vector<int> Hash(1040);
		for(int x:arr1)
			Hash[x]++;
		vector<int> ret;
		for(int x:int arr2)
		{
			while (Hash[x]--)
			{
				ret.pb(x);
			}
		}
		for (int x : arr1)
			while (Hash[x]--)
			{
				ret.pb(x);
			}
		return ret;
	}
};