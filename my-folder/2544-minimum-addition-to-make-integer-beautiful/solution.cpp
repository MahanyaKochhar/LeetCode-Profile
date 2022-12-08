class Solution {
public:
    long long binaryexp(long long a,long long b)
    {
        long long res=1;
        while(b>0)
        {
            if(b&1)
                res=res*a;
            a=a*a;
            b=b/2;
        }
        return res;
    }
    int countsum(long long  no)
    {
        int sum=0;
        while(no!=0)
        {
            int ld=no%10;
            no=no/10;
            sum+=ld;
        }
        return sum;
    }
    long long makeIntegerBeautiful(long long n, int target)
    {
        long long orig=n;
        int sum=countsum(n);
        int idx=0;
        long long temp=n;
        while(true)
        {
            
            if(sum<=target)
                break;
            
            int ld=temp%10;
            n=n-ld*binaryexp(10,idx);
            n=n+binaryexp(10,idx+1);
            idx++;
            sum=countsum(n);
            temp=n/binaryexp(10,idx);
        }
        return n-orig;
    }
};
