bool good(vector<int>& price,int k,int mid)
{
    int st=1;
    int idx=0;
    for(int j=1;j<price.size();j++)
    {
        if(price[j]-price[idx]>=mid)
        {
            idx=j;
            st++;
        }
    }
    if(st>=k)
        return true;
    else
        return false;
}
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k)
    {
        sort(price.begin(),price.end());
        int l=0,r=1e9;
        while(l+1<r)
        {
            int mid=(l+r)/2;
            if(good(price,k,mid))
                l=mid;
            else
                r=mid;
        }
        return l;
    }
};
