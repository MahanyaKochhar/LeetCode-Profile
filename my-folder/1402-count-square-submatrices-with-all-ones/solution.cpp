class Solution {
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        vector<vector<int>>pre(matrix.size() + 1,vector<int>(matrix[0].size() + 1,0));
        int cnt = 0;
        for(int i = 1 ; i <= matrix.size(); i++)
        {
            for(int j = 1 ; j <= matrix[0].size(); j++)
            {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + matrix[i - 1][j - 1] - pre[i - 1][j - 1];
            }
        }

        for(int i = 1; i <= matrix.size(); i++)
        {
            for(int j = 1 ; j <= matrix[0].size();j++)
            {
                for(int k = 0 ; k < i ; k++)
                {
                    if(i - k >= 1 && j - k >= 1)
                    {
                        int sum = pre[i][j] - pre[i][j - k - 1] - pre[i - k - 1][j] + pre[i - k - 1][j - k - 1];
                        if((k + 1) * (k + 1) == sum)
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
