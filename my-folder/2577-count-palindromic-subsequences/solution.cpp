const int mod=1e9+7;
class Solution {
public:
    int countPalindromes(string s)
    {
        long long int fin=0;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                for(int k=0;k<10;k++)
                {
                    string s1="";
                    s1.push_back(char(i+48));
                    s1.push_back(char(j+48));
                    s1.push_back(char(k+48));
                    s1.push_back(char(j+48));
                    s1.push_back(char(i+48));
                    long long int dp[s.length()+1][6];
                    memset(dp,0,sizeof(dp));
                    for(int j=0;j<s.length()+1;j++)
                        dp[j][0]=1;
                    for(int j=1;j<s.length()+1;j++)
                    {
                        for(int k=1;k<s1.length()+1;k++)
                        {
                            if(s[j-1]==s1[k-1])
                            {
                                dp[j][k]=(dp[j-1][k-1]+dp[j-1][k])%mod;
                            }
                            else
                                dp[j][k]=dp[j-1][k];
                        }
                    }
                    fin=(fin+dp[s.length()][s1.length()])%mod;
                }
            }
        }
        return fin;
    }
};
