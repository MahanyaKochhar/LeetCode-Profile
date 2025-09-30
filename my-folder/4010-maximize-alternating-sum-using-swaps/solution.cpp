class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps)
    {
        vector<vector<int>>adjlist(nums.size());
        vector<int>cc(nums.size(), -1);
        vector<vector<int>>res;
        int curr = 0;
        for(auto& x : swaps)
        {
            adjlist[x[0]].push_back(x[1]);
            adjlist[x[1]].push_back(x[0]);
        }
        auto dfs = [&](auto self,int u,int no) -> void {
            cc[u] = no;
            res[no].push_back(nums[u]);
            for(auto& v : adjlist[u])
            {
                if(cc[v] == -1)
                {
                    self(self,v,no);
                }
            }
        };
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(cc[i] == -1)
            {
                res.push_back({});
                dfs(dfs,i,curr);
                curr++;
            }
        }

        vector<pair<int,int>> ptrs;
        for(int i = 0 ; i < res.size();i++)
        {
            sort(res[i].rbegin(),res[i].rend());
            ptrs.push_back({0,res[i].size() - 1});
        }

        for(int i = 0 ; i < nums.size();i++)
        {
            int component = cc[i];
            auto ptr = ptrs[component];
            int st = ptr.first;
            int end = ptr.second;
            int value;
            if(i % 2 == 0)
            {
                value = res[component][st];
                st++;
                ptrs[component] = {st,end};
            }
            else
            {
                value = res[component][end];
                end--;
                ptrs[component] = {st,end};
            }
            nums[i] = value;
        }
        long long ans = 0;
        for(int i = 0 ; i < nums.size();i++)
        {
            if(i % 2 == 0)
            {
                ans += nums[i];
            }
            else
            {
                ans -= nums[i];
            }
        }
        return ans;
    }
};
