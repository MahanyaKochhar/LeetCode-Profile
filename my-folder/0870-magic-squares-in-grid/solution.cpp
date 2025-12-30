class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0 ; i <= row - 3 ; i++)
        {
            for(int j = 0 ; j <= col - 3 ; j++)
            {
                int l1 = i, r1 = j;
                set<int>s;
                for(int k = l1 ; k < (l1 + 3) ; k++) 
                {
                    for(int l = r1 ; l < (r1 + 3) ; l++)
                    {
                        s.insert(grid[k][l]);
                    }
                }
                if(s.size() == 9 && *s.begin() == 1 && *s.rbegin() == 9)
                {
                    set<int>tsums;
                    for(int k = l1 ; k < l1 + 3 ; k++)
                    {
                        int sum = 0;
                        for(int l = 0 ; l < 3 ; l++)
                        {
                            sum += grid[k][r1 + l];
                        }
                        tsums.insert(sum);
                    }
                    for(int k = r1 ; k < r1 + 3 ; k++)
                    {
                        int sum = 0;
                        for(int l = 0 ; l < 3 ; l++)
                        {
                            sum += grid[l1 + l][k];
                        }
                        tsums.insert(sum);
                    }
                    int diagSum1 = grid[l1][r1] + grid[l1 + 1][r1 + 1] + grid[l1 + 2][r1 + 2];
                    int diagSum2 = grid[l1 + 2][r1] + grid[l1 + 1][r1 + 1] + grid[l1][r1 + 2];
                    tsums.insert(diagSum1);
                    tsums.insert(diagSum2);
                    if(tsums.size() == 1)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
