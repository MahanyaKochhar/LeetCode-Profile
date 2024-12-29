class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid)
    {
        int ans = 0;
        for(int j = 0 ; j < grid[0].size(); j++)
        {
            for(int i = 1 ; i < grid.size() ; i++)
            {
                if(grid[i][j] <= grid[i - 1][j])
                {
                    int ex = grid[i][j];
                    grid[i][j] = grid[i - 1][j] + 1;
                    ans += (grid[i][j] - ex);
                }
            }
        }
        return ans;
    }
};
