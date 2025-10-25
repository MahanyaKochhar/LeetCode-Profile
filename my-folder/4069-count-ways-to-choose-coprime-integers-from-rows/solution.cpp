class Solution {
public:
    int countCoprime(vector<vector<int>>& mat)
    {
        const int mod = 1e9 + 7;
        vector<vector<int>>dp(mat.size() + 1,vector<int>(151,0));
        dp[0][0] = 1;
        for(int i = 1 ; i <= mat.size(); i++)
        {
            for(int j = 1 ; j <= mat[0].size(); j++)
            {
                int curr = mat[i - 1][j - 1];
                for(int k = 0 ; k <= 150 ; k++)
                {
                    int target = __gcd(curr,k);
                    dp[i][target] = (dp[i][target] + dp[i - 1][k]) % (mod);
                }
            }
        }
        return dp[mat.size()][1];
    }
};
