class Solution {
public:
    int minimumAverageDifference(vector<int>& nums)
    {
        vector<long long int>pre(nums.size());
        vector<long long int>suf(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
                pre[i]=nums[i];
            else
                pre[i]=pre[i-1]+nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(i==nums.size()-1)
                suf[i]=nums[i];
            else
                suf[i]=suf[i+1]+nums[i];
        }
        int ans=nums.size();
        long long int val=1e14;
        for(int i=0;i<nums.size();i++)
        {
            long long int lf=pre[i];
            long long int sf=(i==nums.size()-1)? 0:suf[i+1];
            long long int lv=lf/(i+1);
            int r=nums.size()-i-1;
            long long int rv;
            if(r==0)
                rv=0;
            else
                rv=sf/r;
            long long int p=abs(lv-rv);
            if(val>p)
            {
                ans=i;
                val=p;
            }
                
        }
        return ans;
    }
};
