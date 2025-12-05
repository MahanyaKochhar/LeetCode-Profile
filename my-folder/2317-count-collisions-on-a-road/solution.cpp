class Solution {
public:
    int countCollisions(string directions)
    {
        int ans = 0;
        int r = 0,s = 0;
        for(int i = 0 ; i < directions.length();i++)
        {
            if(directions[i] == 'L')
            {
                if(s != 0)
                {
                    ans += 1;
                    s = 1;
                }
                else if(r != 0)
                {
                    ans += (r - 1) + 2;
                    r = 0;
                    s = 1;
                }
            }
            else if(directions[i] == 'R')
            {
                s = 0;
                r++;
            }
            else
            {
                if(r != 0)
                {
                    ans += r;
                    r = 0;
                }
                s = 1;
            }
        }
        return ans;
    }
};
