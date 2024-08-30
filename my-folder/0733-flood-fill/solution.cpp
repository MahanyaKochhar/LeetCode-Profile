class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        queue<pair<int,int>> q;
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        q.push({sr,sc});
        vis[sr][sc] = 1;
        int sColor = image[sr][sc];
        int x_dim[] = {1,-1,0,0};
        int y_dim[] = {0,0,1,-1};
        while(!q.empty())
        {
            pair<int,int> curr = q.front();
            int x = curr.first;
            int y = curr.second;
            q.pop();
            for(int i = 0 ; i < 4 ; i++)
            {
                int currx = x_dim[i] + x;
                int curry = y_dim[i] + y;
                if(currx >=0 && currx < image.size() && curry >= 0 && curry < image[0].size() && !vis[currx][curry] && image[currx][curry] == sColor)
                {
                    q.push({currx,curry});
                    vis[currx][curry] = 1;
                }
            }
            image[x][y] = color;
        }
        return image;
    }
};
