class Solution {
public:
    int longestSquareStreak(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        map<int,int>mp;
        int ans=1;
        for(int i=0;i<nums.size();i++)
        {
        	int x=sqrt(nums[i]);
        	if(x*x==nums[i])
        	{
        		mp[nums[i]]=mp[x]+1;
        		ans=max(ans,mp[nums[i]]);
        	}
        	else
        		mp[nums[i]]=1;
        }
        if(ans==1)
        	return -1;
        else
        	return ans;
    }
};
