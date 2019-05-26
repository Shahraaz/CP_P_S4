class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int> barcodes) {
        int n = barcodes.size();
        vector<int> Count(10001);
        for(auto x:barcodes)
            Count[x]++;
        typedef pair<int,int> pii;
        priority_queue<pii> Q;
        for(int i=1;i<=10000;++i)
            if(Count[i]) Q.push({Count[i],i});
        vector<int> C(n+1);
        C[0] = -1;
        for(int i=1;i<=n;++i)
        {
            pii x = Q.top();
            Q.pop();
            pii y = Q.top();
            if(C[i-1]==x.second)
            {
                C[i] = y.second;
                Q.pop();
                y.first--;
                Q.push(y);
            }
            else
            {
                C[i] = x.second;
                x.first--;
            }
            Q.push(x);
            barcodes[i-1] = C[i]; 
        }
        return barcodes;
    }
};