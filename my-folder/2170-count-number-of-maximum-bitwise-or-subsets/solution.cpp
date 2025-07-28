class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums)
    {
        int maxi = 0;
        int ans = 0;
        for(auto& x : nums)
        {
            maxi |= x;
        }
        for(int i = 1 ; i < (1 << nums.size()) ; i++)
        {
            int sum = 0;
            for(int j = 0 ; j < nums.size(); j++)
            {
                if(i & (1 << j))
                {
                    sum |= nums[j];
                }
            }
            if(sum == maxi)
            {
                ans++;
            }
        }
        return ans;
    }
};
