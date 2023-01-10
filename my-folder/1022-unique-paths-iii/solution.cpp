int ans;
class Solution {
public:
    void floodfill(vector<vector<int>>& grid,int x,int y,vector<vector<bool>>&vis,int fin,int cnt)
    {
        if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||grid[x][y]==-1||vis[x][y])
            return;
        vis[x][y]=true;
        fin++;
        if(grid[x][y]==2&&fin==cnt)
        {
            ans++;
            vis[x][y]=false;
            fin--;
            return;
        }
        floodfill(grid,x+1,y,vis,fin,cnt);
        floodfill(grid,x-1,y,vis,fin,cnt);
        floodfill(grid,x,y+1,vis,fin,cnt);
        floodfill(grid,x,y-1,vis,fin,cnt);
        vis[x][y]=false;
        fin--;
    }
    int uniquePathsIII(vector<vector<int>>& grid)
    {
        ans=0;
        int cnt=0,x,y;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]!=-1)
                    cnt++;
                if(grid[i][j]==1)
                {
                    x=i;
                    y=j;
                }
            }
        }
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size()));
        floodfill(grid,x,y,vis,0,cnt);
        return ans;
    }
};
