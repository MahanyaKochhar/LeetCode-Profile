int dp[101][1001][2];
class Solution {
public:
    
    int maxAlice(int curr, int M , vector<int>& piles, int turn)
    {
        if(curr == piles.size())
            return 0;
        int ans;
        if(turn == 0)
            ans = 0;
        else
            ans = INT_MAX;
        if(dp[curr][M][turn] != -1)
            return dp[curr][M][turn];
        for(int i = 1 ; i <= 2 * M ; i++)
        {
            int sum = 0;
            int j = curr;
            for( j = curr ; j < min(i + curr, (int)piles.size()) ; j++)
            {
                sum += piles[j];
            }
            if(turn == 0)
                ans = max(ans, sum + maxAlice(j , max(i,M), piles,1));
            else if(turn == 1)
                ans = min(ans, maxAlice(j, max(i , M), piles, 0));
        }
        return dp[curr][M][turn] = ans;
    }
    int stoneGameII(vector<int>& piles)
    {
        memset(dp,-1,sizeof(dp));
        return maxAlice(0, 1 , piles, 0);
    }
};
