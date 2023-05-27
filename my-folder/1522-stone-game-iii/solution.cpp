int dp[50001][2];
class Solution {
public:
    int maxAlice(int i, vector<int>&stoneValue , int turn)
    {
        if(i >= stoneValue.size())
           return 0;
        int sum = 0;
        int ans;
        if(turn == 0)
            ans = INT_MIN;
        else
            ans = INT_MAX;
        if(dp[i][turn] != -1e9)
            return dp[i][turn];
        for(int j = i ; j < min((int)(stoneValue.size()),i + 3) ; j++)
        {
            sum += stoneValue[j];
            if(turn == 0)
                ans = max(ans , sum + maxAlice(j + 1, stoneValue,1));
            else
                ans = min(ans,maxAlice(j + 1, stoneValue, 0));
        }
        return dp[i][turn] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue)
    {
        for(int i = 0 ; i < 50001; i++)
        {
            for(int j = 0 ; j < 2 ; j++)
            {
                dp[i][j] = - 1e9;
            }
        }
        int ans = maxAlice(0, stoneValue,0);
        int t_sum = 0;
        for(int i = 0 ; i < stoneValue.size() ; i++)
        {
            t_sum += stoneValue[i];
        }
        if(ans > t_sum - ans)
        {
            return "Alice";
        }
        else if(ans < t_sum - ans)
            return "Bob";
        else
            return "Tie";

    }
};
