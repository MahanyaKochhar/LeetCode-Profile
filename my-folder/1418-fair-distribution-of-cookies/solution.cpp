class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k)
    {
        vector<int>assigned(k,0);
        auto assignCookies = [&](auto self,int i) -> int
        {
            int ans = INT_MAX;
            if(i < 0)
            {
                int maxi = -1;
                for(auto& x : assigned)
                {
                    maxi = max(maxi,x);
                }
                return maxi;
            }
            for(int j = 0; j < k; j++)
            {
                assigned[j] += cookies[i];
                ans = min(ans,self(self,i - 1));
                assigned[j] -= cookies[i];
            }
            return ans;
        };

        return assignCookies(assignCookies,cookies.size() - 1);
    }
};
