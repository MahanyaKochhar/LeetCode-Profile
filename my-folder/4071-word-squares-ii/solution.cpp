class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words)
    {
        set<vector<string>>ans;
        vector<bool>vis(words.size(), false);
        auto solve = [&](auto self,vector<string> curr) -> void 
        {
            if(curr.size() == 4)
            {
                if(curr[0][0] == curr[1][0] && curr[0][3] == curr[2][0] && curr[3][0] == curr[1][3] && curr[3][3] == curr[2][3])
                {
                    ans.insert(curr);
                }
                return;
            }

            for(int i = 0 ; i < words.size() ; i++)
            {
                if(!vis[i])
                {
                    vis[i] = true;
                    curr.push_back(words[i]);
                    self(self,curr);
                    vis[i] = false;
                    curr.pop_back();
                }
            }
        };

        solve(solve,{});
        vector<vector<string>>fin;
        for(auto& x : ans)
        {
            fin.push_back(x);
        }
        return fin;
    }
};
