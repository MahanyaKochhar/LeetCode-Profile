class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid)
    {
        int skip = 0;
        vector<int>results;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            if(i % 2 == 0)
            {
                for(int j = 0 ; j < grid[i].size() ; j++)
                {
                    if(skip == 0)
                    {
                        results.push_back(grid[i][j]);
                        skip = 1;
                    }
                    else
                    {
                        skip = 0;
                    }
                }
            }
            else
            {
                for(int j = grid[i].size() - 1 ; j >= 0 ; j--)
                {
                    if(skip == 0)
                    {
                        results.push_back(grid[i][j]);
                        skip = 1;
                    }
                    else
                    {
                        skip = 0;
                    }
                }
            }
        }
        return results;
    }
};
