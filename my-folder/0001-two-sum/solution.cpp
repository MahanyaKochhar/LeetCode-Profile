class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int,int>mp;
        vector<int>ans;
        for(int j=0;j<nums.size();j++)
        {
            int t=target-nums[j];
            if(mp.find(t)!=mp.end())
            {
                
                ans.push_back(j);
                ans.push_back(mp[t]);
                return ans;
            }
            mp[nums[j]]=j;
        }
        return ans;
    }
};
