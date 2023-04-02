bool cmp(const pair<int,int>&a ,const pair<int,int>&b)
{
    return a.first > b.first;
}
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k)
    {
        // int dp[reward1.size() + 1 ][k + 1];
        // // memset(dp,0, sizeof(dp));
        // dp[0][0] = 0;
        // for(int i = 1 ; i < k ;i++)
        //     dp[0][i] = INT_MIN;
        // for(int i = 1 ; i <= reward1.size() ; i++)
        // {
        //     for(int j = 0 ; j <= k ; j++)
        //     {
        //         if(j == 0)
        //             dp[i][j] = dp[i - 1][0] + reward2[i - 1];
        //         else if(j != 0)
        //         {
        //             dp[i][j] = max(dp[i - 1][j] + reward2[i - 1], dp[i - 1][j - 1] + reward1[i - 1]);
        //         }
        //     }
        // }
        // return (int)dp[reward1.size()][k];
        vector<pair<int,int>>pa;
        for(int i = 0 ; i < reward1.size() ; i++)
        {
            pa.push_back({reward1[i] - reward2[i] , i});
        }
        sort(pa.begin() , pa.end() , cmp);
        int ans = 0;
        for(int i = 0 ; i < pa.size() ;i++)
        {
            if(i < k)
                ans += reward1[pa[i].second];
            else
                ans += reward2[pa[i].second];
        }
        return ans;
    }
};
