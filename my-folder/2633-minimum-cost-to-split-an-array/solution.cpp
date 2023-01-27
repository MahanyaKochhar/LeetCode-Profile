class Solution {
public:
    int minCost(vector<int>& nums, int k)
    {
        int uq[nums.size()][nums.size()];
        memset(uq,0,sizeof(uq));
        for(int i=0;i<nums.size();i++)
        {
            vector<bool>vis(1000);
            vector<int>cnt(1000);
            int ans=0;
            for(int j=i;j<nums.size();j++)
            {
                if(!vis[nums[j]])
                {
                    ans++;
                    vis[nums[j]]=true;
                }
                else
                {
                    if(cnt[nums[j]]==0)
                    {
                        ans--;
                        cnt[nums[j]]++;
                    }
                }
                uq[i][j]=ans;
            }
        }
        int dp[nums.size()];
        
        for(int i=0;i<nums.size();i++)
        {
            dp[i]=INT_MAX;
            for(int j=i;j>=0;j--)
            {
                dp[i]=min(dp[i], i-j + 1 - uq[j][i] + k + ((j-1>=0) ? dp[j-1]:0));
            }
        }
        return dp[nums.size()-1];
    }
};
