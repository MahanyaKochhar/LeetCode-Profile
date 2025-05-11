class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid)
    {
        vector<long long>row(grid.size() + 1,0);
        vector<long long>col(grid[0].size() + 1,0);
        for(int i = 1 ; i <= grid.size() ; i++)
        {
            for(int j = 1 ; j <= grid[0].size() ; j++)
            {
                row[i] += grid[i - 1][j - 1];
            }
            row[i] += row[i - 1];
        }

        for(int j = 1 ; j <= grid[0].size() ; j++)
        {
            for(int i = 1 ; i <= grid.size() ; i++)
            {
                col[j] += grid[i - 1][j - 1];
            }
            col[j] += col[j - 1];
        }

        for(int r = 1 ; r < grid.size();r++)
        {
            long long s1 = row[r];
            long long s2 = row[grid.size()] - row[r];
            if(s1 == s2)
            {
                return true;
            }
        }
        for(int c = 1 ; c < grid[0].size(); c++)
        {
            long long s1 = col[c];
            long long s2 = col[grid[0].size()] - col[c];
            if(s1 == s2)
            {
                return true;
            }
        }

        return false;

        

        
    }
};
