class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit)
    {
        int l = 0;
        multiset<int>s;
        int ans = -1;
        for(int r = 0 ; r < nums.size(); r++)
        {
            s.insert(nums[r]);
            while(*(s.rbegin()) - *(s.begin()) > limit)
            {
                auto it = s.find(nums[l]);
                s.erase(it);
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
