class Solution {
public:
    int smallestValue(int n)
    {
        int ans=1e9;
        int prev=-1;
        int tmp;
        while(prev!=n)
        {
            tmp=n;
            int sum=0;
            while(n%2==0)
            {
                sum+=2;
                n=n/2;
            }
            for(int j=3;j*j<=n;j+=2)
            {
                while(n%j==0)
                {
                    sum+=j;
                    n=n/j;
                }
            }
            if(n!=1)
            {
                sum+=n;
            }
            
            ans=min(ans,sum);
            n=sum;
            prev=tmp;
        }
        return ans;
    }
};
