class Solution {
public:
    vector<vector<int>>ans;
    void findsol(vector<int> nums,vector<int>vec,vector<bool>vis)
    {
        if(vec.size()==nums.size())
        {
            ans.push_back(vec);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!vis[i])
            {
                vec.push_back(nums[i]);
                vis[i]=true;
                findsol(nums,vec,vis);
                    vis[i]=false;
                vec.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<int>vec;
        vector<bool>vis(nums.size());
        findsol(nums,vec,vis);
        return ans;
    }
};
