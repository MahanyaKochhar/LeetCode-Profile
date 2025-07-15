class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs)
    {
        vector<int>dp(pairs.size(),1);
        auto cmp = [](const vector<int>&a, const vector<int>&b) -> bool {
            return a[1] < b[1];
        };
        sort(pairs.begin(),pairs.end(),cmp);
        int fin = 0;
        for(int i = 0 ; i < pairs.size();i++)
        {
            int maxi = 0;
            for(int j = i - 1; j >= 0 ; j--)
            {
                if(pairs[j][1] < pairs[i][0])
                    maxi = max(maxi,dp[j]);
            }
            dp[i] += maxi;
            fin = max(fin,dp[i]);
        }
        return fin;
    }
};
