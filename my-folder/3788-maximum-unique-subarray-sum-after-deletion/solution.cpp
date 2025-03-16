class Solution {
public:
    int maxSum(vector<int>& nums)
    {
        int maxi = -200;
        for(auto x : nums)
        {
            maxi = max(maxi,x);
        }
        if(maxi <=0 )
        {
            return maxi;
        }
        else
        {
            int ans = 0;
            vector<bool>vis(101,false);
            for(auto x : nums)
            {
                if(x >= 0 && !vis[x])
                {
                    ans += x;
                    vis[x] = true;
                }
            }
            return ans;
        }
        return 0;
    }
};
