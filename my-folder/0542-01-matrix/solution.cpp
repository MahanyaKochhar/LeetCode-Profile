class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        vector<vector<int>>fin(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<bool>>vis(mat.size(),vector<bool>(mat[0].size(),false));
        queue<pair<int,int>>q;
        auto bfs = [&] () -> void {
            vector<int> x1 = {1,-1,0,0};
            vector<int> y1 = {0,0,1,-1};
            while(!q.empty())
            {
                pair<int,int> element = q.front();
                q.pop();
                int curr = fin[element.first][element.second];
                for(int k = 0 ; k < x1.size() ; k++)
                {
                    int x = x1[k] + element.first;
                    int y = y1[k] + element.second;
                    if(x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size() && !vis[x][y])
                    {
                        vis[x][y] = true;
                        fin[x][y] = curr + 1;
                        q.push({x,y});
                    }   
                }
            }
        };

        for(int i = 0 ; i < mat.size() ; i++)
        {
            for(int j = 0 ; j < mat[i].size() ; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
        }
        bfs();
        return fin;
    }
};
