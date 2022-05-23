typedef long long int lli;
class Solution {
public:
    bool isUgly(int n)
    {
        if(n<=0)
            return false;
        lli m=n;
        while(m%2==0)
        {
            m=m/2;
        }
        for(int i=3;i<=5;i+=2)
        {
            while(m%i==0)
            {
                m=m/i;
            }
        }
        if(m==1)
            return true;
        else
            return false;
    }
};
