class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix)
    {
        using ll = long long;
        ll sum = 0;
        int cnt = 0;
        int mini = INT_MAX;
        for(int i = 0 ; i < matrix.size() ; i++)
        {
            for(int j = 0 ; j < matrix[i].size() ; j++)
            {
                if(matrix[i][j] < 0)
                {
                    cnt++;
                }
                sum += abs(matrix[i][j]);
                mini = min(mini,abs(matrix[i][j]));
            }
        }
        return ((cnt % 2 == 0) ? sum : sum - 2 * mini);
    }
};
