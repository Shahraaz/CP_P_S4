class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        set<pair<int,int>> NextElement;
        int n = A.size();
        for(int i=n-1;i>=0;--i)
        {
            auto it = NextElement.upper_bound({-A[i],-i});
            if(it!=NextElement.end())
            {   
                swap(A[i],A[-it->second]);
                break;
            }
            NextElement.insert({-A[i],-i});
        }
        return A;
    }
};