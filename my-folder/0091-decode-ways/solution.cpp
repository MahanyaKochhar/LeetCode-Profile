class Solution {
public:
    int dp[101];
    int count=0;
    int numDecodings(string s) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
       int ans=no1(s,n,0); 
        
        return ans; 
    }
   int no1(string s,int n,int pos)
    {
        if(pos>=n)
        {
            
            return 1;
        }
       int x=s[pos]-'0';
         if(x==0)
         {
         return 0;
         }
       if(dp[pos]!=-1)
           return dp[pos];
      
     if(int(s[pos]-'0')==1&&(pos+1<=n-1)&&int(s[pos+1]-'0')>=0&&int(s[pos+1]-'0')<=9)
        {
           return dp[pos]=no1(s,n,pos+1)+no1(s,n,pos+2);
            
        }
       else if((int(s[pos]-'0')==2&&(pos+1<=n-1)&&int(s[pos+1]-'0')>=0&&int(s[pos+1]-'0')<=6))
           return dp[pos]=no1(s,n,pos+1)+no1(s,n,pos+2);
       
       
       
          else
        {
            return dp[pos]=no1(s,n,pos+1);
        }
       }
        
    };
