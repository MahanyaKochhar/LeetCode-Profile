long long int binaryexp(long long int a,long long int b)
{
long long int res=1;
while(b>0)
{
    if(b&1)
    {
      res=(res*a);
    }
    a=(a*a);
    b>>=1;

}
return res;
}

class Solution {
public:
    int reverse(int x)
    {
        // while(x!=0)
        // {
        //     if(x&1)
        //         cout<<1;
        //     else
        //         cout<<0;
        //     x=x/2;
        // }
        // return 0;
        int e=0;
        if(x<0)
            e=1;
        int tmp=x;
        int cnt=0;
        while(tmp!=0)
        {
        	cnt++;
        	tmp=tmp/10;
        }
        cnt--;
        long long int ans=0;
        while(x!=0)
        {
        	int ld=x%10;
            ld=abs(ld);
        	ans=ans+ld*binaryexp(10,cnt);
        	cnt--;
        	x=x/10;
        }
        if(e==1)
        	ans=0-ans;
        if(ans>=INT_MIN&&ans<=INT_MAX)
        	return (int)ans;
        else
        	return 0;

    }
};
