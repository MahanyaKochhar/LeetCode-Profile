class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int val)
    {
        set<int>seen;
        map<int,int>mp;
        for(int i = 0 ; i < nums.size();i++)
        {
            int rem = (nums[i] % val + val) % val;
            int curr = mp.contains(rem) ? mp[rem] : 0;
            seen.insert(rem + curr * val);
            mp[rem] = curr + 1;
        }
        for(int i = 0 ; i < 1e5 + 2;i++)
        {
            if(!seen.contains(i))
            {
                return i;
            }
        }
        return 0;
    }
};
