class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries)
    {
        long long ans = 0;
        int rows = 0 , cols = 0;
        vector<bool>r(n),c(n);
        for(int i = queries.size() - 1 ; i >= 0 ; i--)
        {
            if(queries[i][0] == 1)
            {
                if(!c[queries[i][1]])
                {
                    ans = (ans + queries[i][2] * (n - rows));
                    cols++;
                    c[queries[i][1]] = true;
                }
                
            }
            else
            {
                if(!r[queries[i][1]])
                {
                    ans = (ans + queries[i][2] * (n - cols));
                    rows++;
                    r[queries[i][1]] = true;
                }
            }
        }
        return ans;
    }
};
