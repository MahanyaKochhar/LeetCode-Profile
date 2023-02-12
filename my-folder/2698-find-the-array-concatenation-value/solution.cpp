long long binaryexp(long long int A,long long int B)
{
    long long res=1;
    while(B>0)
    {
        if(B&1)
            res=res*A;
        A=A*A;
        B=B/2;
    }
    return res;
}
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums)
    {
        int l=0,r=nums.size()-1;
        long long ans = 0;
        while(l<=r)
        {
            if(l==r)
            {
                ans+=nums[l];
                l++;
                r--;
            }
            else
            {
                int tmp=nums[r];
                int cnt=0;
                while(tmp!=0)
                {
                    cnt++;
                    tmp=tmp/10;
                }
                long long b=nums[l]*binaryexp(10,cnt);
                ans+=(b+nums[r]);
                l++;
                r--;
            }
        }
        return ans;
    }
};
