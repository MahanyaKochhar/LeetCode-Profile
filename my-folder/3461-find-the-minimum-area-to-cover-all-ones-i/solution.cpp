class Solution {
public:
    int minimumArea(vector<vector<int>>& grid)
    {
        int l1 = 1e5, l2 = -1 , r1 = 1e5 , r2 = -1 ;
        for(int i = 0 ; i < grid.size(); i++)
        {
            for(int j = 0 ; j < grid[i].size(); j++)
            {
                if(grid[i][j])
                {
                    l1 = min(l1,i);
                    l2 = max(l2,i);
                    r1 = min(r1,j);
                    r2 = max(r2,j);
                }
            }
        }
        return (l2 - l1 + 1) * (r2 - r1 + 1);
    }
};
