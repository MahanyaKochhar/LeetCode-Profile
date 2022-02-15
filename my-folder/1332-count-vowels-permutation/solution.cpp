typedef long long int lli;
class Solution {
public:
    int countVowelPermutation(int n)
    {
        const lli mod=1000000007;
        vector<vector<lli>>dp(n+1,vector<lli>(6,0));
        for(int i=1;i<=5;i++)
            dp[1][i]=1;
        for(int j=2;j<=n;j++)
        {
            for(int k=1;k<=5;k++)
            {
                if(k==1)
                    dp[j][k]=(dp[j-1][2]+dp[j-1][3]+dp[j-1][5])%mod;
                else if(k==2)
                    dp[j][k]=(dp[j-1][1]+dp[j-1][3])%mod;
                else if(k==3)
                    dp[j][k]=(dp[j-1][2]+dp[j-1][4])%mod;
                else if(k==4)
                    dp[j][k]=dp[j-1][3];
                else
                    dp[j][k]=(dp[j-1][3]+dp[j-1][4])%mod;
            }
        }
        int fin=0;
        for(int k=1;k<=5;k++)
        {
            fin=(fin+(dp[n][k]))%mod;
        }
        return fin;
        
    }
};
