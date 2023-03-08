class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        queue< pair< int , pair< int , int>>>q;
        int time = 0;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[i].size() ; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({0,{i,j}});
                }
            }
        }
        int x1[4] = {-1 , 1 , 0 , 0};
        int y1[4] = {0, 0 , 1 , -1};
        while(!q.empty())
        {
            
            pair< int , pair<int,int>> p = q.front();
            time = max(time,p.first);
            q.pop();
            for(int i = 0 ; i < 4 ; i++)
            {
                int x = p.second.first + x1[i];
                int y = p.second.second + y1[i];
                if(x >= 0 && x < grid.size() && y >=0 && y < grid[0].size() && grid[x][y] == 1)
                {
                    grid[x][y] = 2;
                    q.push({p.first + 1 , {x , y}});
                }
            }
            
        }
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[i].size() ; j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return time;
        
    }
};
