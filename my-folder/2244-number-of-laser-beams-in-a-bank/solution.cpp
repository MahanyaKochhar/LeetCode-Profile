class Solution {
public:
    int numberOfBeams(vector<string>& bank)
    {
        int ans = 0;
        int ex = 0,nx = 0;
        int i = 0;
        for(i = 0 ; i < bank.size(); i++)
        {
            string s = bank[i];
            for(int j = 0 ; j < s.length(); j++)
            {
                if(s[j] == '1')
                {
                    ex++;
                }
            }
            if(ex != 0)
            {
                break;
            }
        }
        for(int j = i + 1; j < bank.size(); j++)
        {
            string s = bank[j];
            for(int k = 0 ; k < s.length(); k++)
            {
                if(s[k] == '1')
                {
                    nx++;
                }
            }
            if(nx != 0)
            {
                ans += (ex * nx);
                ex = nx;
                nx = 0;
            }
        }
        return ans;
    }
};
