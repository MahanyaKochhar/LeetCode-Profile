class Solution {
public:
    int pivotInteger(int n)
    {
        for(int i=1;i<=n;i++)
        {
            int lf=(i*(i+1))/2;
            int rf=(n-i+1)*i+(((n-i)*(n-i+1))/2);
            if(lf==rf)
                return i;
        }
        return -1;
    }
};
