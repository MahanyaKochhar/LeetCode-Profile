class Solution {
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int curr = 0;
        int ans = 0;
        for(int i = grid.size() - 1 ; i >= 0 ; i--)
        {
            int e = 0;
            for(int j = curr ; j < grid[0].size() ; j++)
            {
                if(grid[i][j] < 0)
                {
                    ans += grid[0].size() - j;
                    curr = j;
                    e = 1;
                    break;
                }
            }
            if(e == 0)
            {
                break;
            }
        }
        return ans;
    }
};
