class Solution {
public:
    bool good(long long int val,int sz)
    {
        if((val*(val+1))/2<=sz)
            return true;
        else
            return false;
    }
    int maximumGroups(vector<int>& grades)
    {
        int l=1,r=1e5+1;
        while(l+1<r)
        {
            int mid=(l+r)/2;
            if(good(mid,grades.size()))
                l=mid;
            else
                r=mid;
        }
        return l;
    }
};
