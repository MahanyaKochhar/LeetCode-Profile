const int mod=1e9+7;
int binaryexp(long long int A,long long int B)
{
    long long int res=1;
    while(B>0)
    {
        if(B&1)
            res=(res*A)%mod;
        A=(A*A)%mod;
        B=B/2;
    }
    return (int)res;
}
class Solution {
public:
    int monkeyMove(int n)
    {
        return (binaryexp(2,n)-2+mod)%mod;
    }
};
