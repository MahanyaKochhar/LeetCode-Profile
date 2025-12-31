class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells)
    {
        
        int l = 0 , r = cells.size() + 1;
        auto good = [&](int idx) -> bool
        {
            vector<vector<int>>matrix(row + 1,vector<int>(col + 1,0));
            for(int i = 0 ; i < idx ; i++)
            {
                matrix[cells[i][0]][cells[i][1]] = 1;
            }
            queue<pair<int,int>>q;
            vector<vector<bool>>visited(row + 1,vector<bool>(col + 1, false));
            for(int i = 1 ; i <= col ; i++)
            {
                if(matrix[1][i] == 0)
                {
                    q.push({1,i});
                    visited[1][i] = true;
                }
            }

            while(!q.empty())
            {
                auto ele = q.front();
                q.pop();
                int x = ele.first;
                int y = ele.second;
                if(x == row)
                {
                    return true;
                }
                int xpos[] = {-1,1,0,0};
                int ypos[] = {0,0,1,-1};
                for(int i = 0 ; i < 4 ; i++)
                {
                    int newx = xpos[i] + x;
                    int newy = ypos[i] + y;
                    if(newx >= 1 && newx <= row && newy >= 1 && newy <= col && matrix[newx][newy] == 0 && !visited[newx][newy])
                    {
                        q.push({newx,newy});
                        visited[newx][newy] = true;
                    }
                }
            }
            return false;
        };

        while(l + 1 < r)
        {
            int mid = (l + r) / 2;
            if(good(mid))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};
