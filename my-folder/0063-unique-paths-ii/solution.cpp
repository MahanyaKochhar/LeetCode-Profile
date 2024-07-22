class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        vector<vector<int>> grid(obstacleGrid.size() + 2,vector<int>(obstacleGrid[0].size() + 2,0));
        for(int i = 1 ; i <= obstacleGrid.size() ; i++)
        {
            for(int j = 1 ; j<= obstacleGrid[i - 1].size() ; j++)
            {
                if(obstacleGrid[i - 1][j - 1] != 1)
                {
                    grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
                    if(i == 1 && j == 1)
                    {
                        grid[i][j] = 1;
                    }
                }
                else {
                    grid[i][j] = 0;
                }
            }
        }
        return grid[obstacleGrid.size()][obstacleGrid[0].size()];
    }
};
