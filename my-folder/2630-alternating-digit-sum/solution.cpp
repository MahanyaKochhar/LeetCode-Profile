class Solution {
public:
    int alternateDigitSum(int n)
    {
        stack<int>s;
        while(n!=0)
        {
            int ld=n%10;
            s.push(ld);
            n=n/10;
        }
        int sum=0,cnt=0;
        while(!s.empty())
        {
            if(cnt==0)
            {
                sum+=s.top();
                s.pop();
                cnt=1;
            }
            else
            {
                sum-=s.top();
                s.pop();
                cnt=0;
            }
        }
        return sum;
    }
};
