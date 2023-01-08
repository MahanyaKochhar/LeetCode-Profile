const int p=37;
const int mod=1e9+7;
int binaryexp(long long int A,long long int B)
{
    int res=1;
    while(B>0)
    {
        if(B&1)
            res=(res*A)%mod;
        A=(A*A)%mod;
        B=B/2;
    }
    return res;
}
class Solution {
public:
    int deleteString(string s)
    {
        int hash[s.length()][s.length()];
        memset(hash,0,sizeof(hash));
        for(int i=0;i<s.length();i++)
        {
            long long int power=1;
            long long int curr=0;
            for(int j=i;j<s.length();j++)
            {
                curr=(curr+(power*(s[j]-'a'+1))%mod)%mod;
                hash[i][j]=curr;
                power=(power*p)%mod;
            }
        }
        vector<long long int>dp(s.length()+1,-1e6);
        dp[0]=0;
        for(int i=0;i<s.length();i++)
        {
            int l1=i+1;
            int r2=i;
            for(int j=i+1;j<s.length();j++)
            {
                int r1=j;
                int len=j-l1+1;
                int l2=i-len+1;
                if(l2<0)
                    break;
                if(hash[l2][r2]==hash[l1][r1])
                {
                    dp[i+1]=max(dp[i+1],1+dp[l2]);
                }
            }
        }
        long long int result=1;
        for(int i=1;i<=s.length();i++)
        {
            result=max(result,dp[i]+1);
        }
        return result;
    }
};
