class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries)
    {
    
        int all0 = true;
        for(int i = 0 ; i < nums.size();i++)
        {
            if(nums[i] != 0)
                all0 = false;
        }
        if(all0)
            return 0;
        bool dp[10][1001][1001];
        memset(dp,false,sizeof(dp));
        for(int i = 0 ; i < nums.size();i++)
        {
            dp[i][0][0] = true;
        }
        for(int i = 0 ; i < queries.size();i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            int v = queries[i][2];
            for(int j = 0 ; j < nums.size() ; j++)
            {
                for(int k = 0 ; k <= 1000; k++)
                {
                    if(k >= v && j >= l && j <= r)
                    {
                        dp[j][k][i + 1] = dp[j][k][i] | dp[j][k - v][i];
                    }
                    else
                    {
                        dp[j][k][i + 1] = dp[j][k][i];
                    }
                }
            }
            int e = 0;
            for(int j = 0 ; j < nums.size();j++)
            {
                if(dp[j][nums[j]][i + 1])
                {
                    continue;
                }
                else
                    e = 1;
            }
            if(e == 0)
            {
                return i + 1;
            }
        }
        return -1;

    }
};
