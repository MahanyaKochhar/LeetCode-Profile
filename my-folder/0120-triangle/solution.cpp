class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),INT_MAX));
        for(int i = 0 ; i < triangle.size();i++)
        {
            for(int j = 0 ; j < triangle[i].size(); j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = triangle[i][j];
                    continue;
                }
                dp[i][j] = triangle[i][j] + min(j - 1 >= 0 ? dp[i - 1][j - 1] : INT_MAX,j < triangle[i - 1].size() ? dp[i - 1][j] : INT_MAX);
            }
        }
        int ans = INT_MAX;
        for(int j = 0 ; j < triangle[triangle.size() - 1].size(); j++)
        {
            ans = min(ans, dp[triangle.size() - 1][j]);
        }
        return ans;
        
    }
};
