class Solution {
public:
    int smallestNumber(int n)
    {
        int st = 0;
        for(int i = 0; i < 10;i++)
        {
            if((1 << i) & n)
            {
                st = i;
            }
        }
        return pow(2,st + 1) - 1;
    }
};
