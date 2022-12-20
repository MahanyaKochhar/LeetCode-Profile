class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        vector<bool>vis(rooms.size(),false);
        auto dfs=[&](auto self,int node)->void
        {
            vis[node]=true;
            for(auto x:rooms[node])
            {
                if(vis[x])
                continue;
                self(self,x);
            }

        };
        dfs(dfs,0);
        bool ans=true;
        for(int i=0;i<rooms.size();i++)
            ans=ans && vis[i];
        return ans;
    }
};
