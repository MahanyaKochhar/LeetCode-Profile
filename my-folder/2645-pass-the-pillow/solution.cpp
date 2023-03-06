class Solution {
public:
    int passThePillow(int n, int time)
    {
        int cnt = 0;
        int pos = 1;
        while(time != cnt)
        {
            if(pos == 1)
            {
                while(pos < n && time !=cnt)
                {
                    pos++;
                    cnt++;
                }
            }
            else if(pos == n)
            {
                while(pos > 1 && time!=cnt)
                {
                    cnt++;
                    pos--;
                }
            }
        }
        return pos;
    }
};
