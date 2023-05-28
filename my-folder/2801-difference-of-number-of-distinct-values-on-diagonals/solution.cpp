class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid)
    {
        vector<vector<int>>ans(grid.size() , vector<int>(grid[0].size(),0));
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[i].size() ; j++)
            {
                int cnt = 1;
                set<int>s,s1;
                while(true)
                {
                    if(i - cnt >= 0 && j - cnt >= 0)
                    {
                        s.insert(grid[i - cnt][j - cnt]);
                        cnt ++;
                    }
                    else
                        break;
                }
                cnt = 1;
                while(true)
                {
                    if(i + cnt < grid.size() && j + cnt < grid[0].size())
                    {
                        s1.insert(grid[i + cnt][j + cnt]);
                        cnt ++;
                    }
                    else
                        break;
                }
                ans[i][j] = abs((int)s1.size() - (int)s.size());
            }
        }
        return ans;
    }
};
