class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
    	vector<vector<int>>dp(matrix.size(),vector<int>(matrix.size(),100000));
        for(int i=0;i<matrix.size();i++)
        {
        	dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<matrix.size();i++)
        {
        	for(int j=0;j<matrix.size();j++)
        	{
        		if(j-1>=0)
        			dp[i][j]=min(dp[i][j],dp[i-1][j-1]+matrix[i][j]);
        		if(j>=0)
        			dp[i][j]=min(dp[i][j],dp[i-1][j]+matrix[i][j]);
        		if(j+1<matrix.size())
        			dp[i][j]=min(dp[i][j],dp[i-1][j+1]+matrix[i][j]);


        	}
        }
        int mini=100000;
        for(int i=0;i<matrix.size();i++)
        	mini=min(mini,dp[matrix.size()-1][i]);
        return mini;
    }
};
