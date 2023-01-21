class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k)
    {
        long long net_dec=0,net_inc=0;
        for(int i=0;i<nums1.size();i++)
        {
            if(nums1[i]>nums2[i])
            {
                int diff=nums1[i]-nums2[i];
                if(k!=0&&diff%k==0)
                {
                    net_dec+=diff;
                }
                else
                    return -1;
            }
            else if(nums2[i]>nums1[i])
            {
                int diff=nums2[i]-nums1[i];
                if(k!=0&&diff%k==0)
                {
                    net_inc+=diff;
                }
                else
                    return -1;
            }
        }
        if(net_inc==net_dec)
        {
            if(k!=0)
                return net_inc/k;
            else
                return 0;
        }
        else
            return -1;
    }
};
