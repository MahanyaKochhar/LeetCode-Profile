class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        map<int,int>mp;
        mp.clear();
        int sum=0;
        int ans=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum=(sum+nums[i]+10000*k)%k;
            ans+=mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};
