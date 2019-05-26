int _n;
vector<long long> Sum;
void pre(vector<int> &a)
{
    _n = a.size();
    Sum.resize(_n);
    Sum[0] = a[0];
    for(int i=1;i<_n;++i)
        Sum[i] = Sum[i-1] + a[i];
}
long long getsum(int start,int end)
{
    if(start<0 || start>=_n || end<0 || end>=_n)
        return 0;
    if(start==0) return Sum[end];
    return Sum[end] - Sum[start-1];
}
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        _n = customers.size();
        vector<int> V(_n);
        long long a = 0;
        for(int i=0;i<_n;++i)
        {
            V[i] = grumpy[i]*customers[i];
            customers[i] = (1-grumpy[i])*customers[i];
            a += customers[i];
        }
        pre(V);
        long long answer = a;
        for(int i=0;i<_n;++i)
            answer = max(answer,a+getsum(i,i+X-1));
        return answer;
    }
};