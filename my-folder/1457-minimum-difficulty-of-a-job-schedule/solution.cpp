class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d)
    {
        long long int dp[jobDifficulty.size()+1][d+1][1001];
        for(int i=0;i<jobDifficulty.size()+1;i++)
        {
            for(int j=0;j<d+1;j++)
            {
                for(int k=0;k<=1000;k++)
                {
                    dp[i][j][k]=INT_MAX;
                }
            }
        }
        dp[0][0][0]=0;
        for(int i=1;i<jobDifficulty.size()+1;i++)
        {
            for(int j=1;j<=d;j++)
            {
                // if(j>i)
                //     continue;
                for(int k=0;k<=1000;k++)
                    dp[i][j][jobDifficulty[i-1]]=min(dp[i][j][jobDifficulty[i-1]],dp[i-1][j-1][k]+jobDifficulty[i-1]);
                for(int k=0;k<=1000;k++)
                {
                    if(k>=jobDifficulty[i-1])
                        dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]);
                    else
                        dp[i][j][jobDifficulty[i-1]]=min(dp[i][j][jobDifficulty[i-1]],dp[i-1][j][k]-k+jobDifficulty[i-1]);
                }
            }
        }
        long long int ans=INT_MAX;
        for(int i=0;i<=1000;i++)
            ans=min(ans,dp[jobDifficulty.size()][d][i]);
        if(ans!=INT_MAX)
            return (int)ans;
        else
            return -1;
    }
};
