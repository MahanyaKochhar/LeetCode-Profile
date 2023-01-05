bool good(vector<int>nums,int mid)
{
    vector<long long int>nums2(nums.size());
    for(int i=0;i<nums.size();i++)
    {
        nums2[i]=nums[i];
    }
    long long int curr_add=0;
    for(int i=nums2.size()-1;i>=0;i--)
    {
        if(nums2[i]<=mid)
            continue;
        else
        {
            curr_add=nums2[i]-mid;
            if(i-1>=0)
                nums2[i-1]+=curr_add;
            curr_add=0;
        }
        
    }
    if(nums2[0]>mid)
        return false;
    else
        return true;
}
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums)
    {
        int r=-1;
        for(int i=0;i<nums.size();i++)
            r=max(r,nums[i]);
        int l=-1;
        while(l+1<r)
        {
            int mid=(l+r)/2;
            if(good(nums,mid))
                r=mid;
            else
                l=mid;
        }
        return r;
    }
};
