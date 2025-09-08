class Solution {
public:
    vector<int> getNoZeroIntegers(int n)
    {
        vector<int>ans;
        auto check = [&](int a) -> bool {
            while(a != 0)
            {
                int ld = a % 10;
                if(ld == 0)
                {
                    return false;
                }
                a = a / 10;
            }
            return true;
        };
        for(int i = 1 ; 2 * i <= n ; i++)
        {
            int a = i, b = n - i;
            if(check(a) && check(b))
            {
                ans.push_back(a);
                ans.push_back(b);
                return ans;
            }
        }
        return {};
    }
};
