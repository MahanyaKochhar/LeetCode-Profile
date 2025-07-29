class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums)
    {
        vector<int>pos(31,-1);
        vector<int>ans(nums.size(),0);
        for(int j = nums.size() - 1; j >= 0 ; j--)
        {
            int t = nums[j];
            int bit = 0;
            while(t != 0)
            {
                if(t & 1)
                {
                    pos[bit] = j;
                }
                t = t >> 1;
                bit++;
            }
            int fin = j;
            for(auto x : pos)
            {
                if(x != -1)
                {
                    fin = max(x,fin);
                }
            }
            ans[j] = fin - j + 1;
        }
        return ans;
    }
};
