class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int ans = 0;
        vector<int>clone;
        clone.push_back(-1e9 - 2);
        for(auto& x : nums)
        {
            clone.push_back(x);
        }
        clone.push_back(1e9 + 2);
        vector<int>pre(clone.size(),0);
        vector<int>suff(clone.size(),0);
        for(int i = 1 ; i <= nums.size() ; i++)
        {
            if(clone[i] >= clone[i - 1])
            {
                pre[i] = pre[i - 1] + 1;
            }
            else
            {
                pre[i] = 1;
            }
            ans = max(ans,pre[i]);
        }
        for(int j = nums.size() ; j >= 1 ; j--)
        {
            if(clone[j] <= clone[j + 1])
            {
                suff[j] = suff[j + 1] + 1;
            }
            else
            {
                suff[j] = 1;
            }
        }
        for(int i = 1 ; i <= nums.size();i++)
        {
            if(clone[i - 1] <= clone[i + 1])
            {
                ans = max(ans,pre[i - 1] + suff[i + 1] + 1);
            }
            else
            {
                ans = max(ans,max(pre[i - 1] + 1,suff[i + 1] + 1));
            }
        }
        return ans;
    }
};
