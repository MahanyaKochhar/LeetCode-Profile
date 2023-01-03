class Solution {
public:
    int countDigits(int num)
    {
        int no=num;
        int tmp=no;
        int cnt=0;
        while(no!=0)
        {
            int ld=no%10;
            if(tmp%ld==0)
                cnt++;
            no=no/10;
        }
        return cnt;
    }
};
