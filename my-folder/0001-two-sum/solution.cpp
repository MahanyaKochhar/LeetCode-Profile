class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int,int>mp;
        vector<int>v;
       for(int j=0;j<nums.size();j++)
       {
           
           if(mp.find(target-nums[j])!=mp.end())
           {
               return {j,mp[target-nums[j]]};
           }
           mp[nums[j]]=j;
       }
         return v;
    }
};
