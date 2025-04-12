class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k)
    {
        long long ans = 0, sum = 0;
        map<int,int>mp;
        auto validate = [&] (long long curr) -> void {
            if(mp.size() == k)
            {
                ans = max(ans,curr);
            }
        };
        for(int i = 0; i < k ; i++)
        {
            sum += nums[i];
            mp[nums[i]]++;
        }

        validate(sum);

        for(int i = k ; i < nums.size(); i++)
        {
            sum -= nums[i - k];
            sum += nums[i];
            mp[nums[i - k]]--;
            mp[nums[i]]++;
            if(mp[nums[i - k]] == 0)
            {
                mp.erase(nums[i - k]);
            }
            validate(sum);
        }
        return ans;
    }
};
