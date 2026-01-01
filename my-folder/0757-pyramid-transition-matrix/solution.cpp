class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed)
    {
        set<string>permitted(allowed.begin(), allowed.end());
        unordered_map<string,bool>mp;
        auto solve = [&](auto self, string prev, string curr, int idx) -> bool
        {
            if(prev.length() == 1)
            {
                return true;
            }
            string key = prev + '|' + curr + '|' + to_string(idx);
            if(mp.contains(key))
            {
                return mp[key];
            }
            bool ans = false;
            for(int i = 0 ; i < 6 ; i++)
            {
                char ch = (char)('A' + i);
                string res = "";
                res.push_back(prev[idx]);
                res.push_back(prev[idx + 1]);
                res.push_back(ch);
                if(permitted.contains(res))
                {
                    curr.push_back(ch);
                    if(idx == prev.length() - 2)
                    {
                        ans = ans | self(self,curr,"",0);
                    }
                    else
                    {
                        ans = ans | self(self,prev,curr,idx + 1);
                    }
                    if(ans)
                    {
                        mp[key] = ans;
                        return true;
                    }
                    curr.pop_back();
                }
            }
            mp[key] = ans;
            return ans;
        };
        return solve(solve,bottom,"",0);
    }
};
