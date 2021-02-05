class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>mp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            
        }
        int ans=0;
        for(auto y:mp)
        {
          if(mp.find(y.first+1)!=mp.end())
          {
              ans=max(ans,mp[y.first]+mp[y.first+1]);
          }
        }
        return ans;
    }
};
