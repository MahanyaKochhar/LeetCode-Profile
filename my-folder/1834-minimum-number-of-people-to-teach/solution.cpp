class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships)
    {
        map<int,set<int>>mp;
        vector<bool>comm(friendships.size(),false);
        auto constructMap = [&]() -> void {
            for(int i = 0 ; i < languages.size();i++)
            {
                for(int j = 0 ; j < languages[i].size();j++)
                {
                    mp[i + 1].insert(languages[i][j]);
                }
            }
        };

        auto checkCommon = [&]()-> void {
            for(int i = 0 ; i < friendships.size();i++)
            {
                int v = friendships[i][1];
                for(auto& x : mp[v])
                {
                    if(mp[friendships[i][0]].contains(x))
                    {
                        comm[i] = true;
                        break;
                    }
                }
            }
        };
        constructMap();
        checkCommon();
        int ans = 1e5;
        for(int i = 1 ; i <= n ; i++)
        {
            vector<bool>taught(languages.size() + 1);
            int cnt = 0;
            for(int j = 0 ; j < friendships.size();j++)
            {
                if(!comm[j])
                {
                    if(!taught[friendships[j][0]])
                    {
                        if(!mp[friendships[j][0]].contains(i))
                        {
                            taught[friendships[j][0]] = true;
                            cnt++;
                        }
                    }
                    if(!taught[friendships[j][1]])
                    {
                        if(!mp[friendships[j][1]].contains(i))
                        {
                            taught[friendships[j][1]] = true;
                            cnt++;
                        }
                    }
                }
            }
            ans = min(ans,cnt);
        }

        return ans;

    }
};
