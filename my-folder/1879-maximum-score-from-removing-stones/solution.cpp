class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans=min(a,b);
            ans=min(ans,c);
            int finans=INT_MIN;
            if(ans==a)
            {
            for(int j=b;j>=b-ans;j--)
            {
            finans=max(finans,ans+min(j,c-ans));
            c++;
            }}
            else if(ans==b)
            {
for(int j=a;j>=a-ans;j--)
            {
            finans=max(finans,ans+min(j,c-ans));
            c++;
            }
            }
            else
            {
            for(int j=a;j>=a-ans;j--)
            {
            finans=max(finans,ans+min(j,b-ans));
            b++;
            }
            }
            

        return finans;
    }
};
