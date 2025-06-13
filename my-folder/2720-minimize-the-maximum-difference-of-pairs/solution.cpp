class Solution {
public:
    int minimizeMax(vector<int>& nums, int p)
    {
        sort(nums.begin(),nums.end());
        auto good = [&] (int val) -> bool {
            int count = 0;
            vector<bool>vis(nums.size(),false);
            for(int i = 1 ; i < nums.size();i++)
            {
                int diff = abs(nums[i] - nums[i - 1]);
                if(diff <= val && !vis[i - 1])
                {
                    vis[i] = true;
                    vis[i - 1] = true;
                    count++;
                }
            }
            if(count >= p)
            {
                return true;
            }
            else
            {
                return false;
            }
        };

        int r = 1e9 + 2;
        int l = -1;
        while(l + 1 < r)
        {
            int mid = (l + r) / 2;
            if(good(mid))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return r;
    }
};
