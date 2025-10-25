class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2)
    {
        int target = nums2[nums2.size() - 1];
        using ll = long long;
        ll ans = 1;
        vector<int>pre(1e5 + 2, 0);
        for(int i = 0 ; i < nums1.size(); i++)
        {
            ans += abs(nums1[i] - nums2[i]);
            pre[min(nums1[i],nums2[i])] += 1;
            pre[max(nums1[i],nums2[i]) + 1] -= 1;
        }
        for(int i = 1 ; i < pre.size(); i++)
        {
            pre[i] += pre[i - 1];
        }
        int mind = INT_MAX;
        for(int i = 0 ; i < pre.size() ; i++)
        {
            if(pre[i] != 0)
            {
                mind = min(mind, abs(i - target));
            }
        }
        ans += mind;
        return ans;
    }
};
