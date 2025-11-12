class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        int run_gcd = 0;
        int cnt = 0;
        int ans = INT_MAX;
        for(auto& x : nums)
        {
            run_gcd = __gcd(run_gcd,x);
            if(x == 1)
            {
                cnt++;
            }
        }
        if(run_gcd > 1)
        {
            return -1;
        }
        if(cnt != 0)
        {
            return nums.size() - cnt;
        }
        else
        {
            for(int i = 0 ; i < nums.size();i++)
            {
                int curr_gcd = nums[i];
                for(int j = i + 1; j < nums.size(); j++)
                {
                    curr_gcd = __gcd(curr_gcd,nums[j]);
                    if(curr_gcd == 1)
                    {
                        ans = min(ans,j - i - 1 + (int)nums.size());
                    }
                }
            }
            return ans;
        }
        return -1;
    }
};
