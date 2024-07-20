class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum)
    {
        vector<vector<int>> result(rowSum.size(),vector<int>(colSum.size(),0));
        for(int i = 0; i < rowSum.size();i++)
        {
            for(int j = 0 ; j < colSum.size() ; j++)
            {
                int minResult = min(rowSum[i],colSum[j]);
                result[i][j] = minResult;
                rowSum[i] -= minResult;
                colSum[j] -= minResult;
            }
        }
        return result;
    }
};
