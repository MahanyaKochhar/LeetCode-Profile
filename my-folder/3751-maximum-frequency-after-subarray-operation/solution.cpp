class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        map<int,int> mp ;
        int ans= 0;
        for(auto x : nums)
        {
            mp[x]++;
        }

        for(int i = -50 ; i <= 50 ; i++)
        {
            vector<int>temp(nums.size());
            for(int j = 0 ; j < nums.size();j++)
            {
                if(nums[j] + i == k)
                {
                    temp[j] = 1;
                }
                else if(nums[j] == k)
                {
                    temp[j] = -1;
                }
                else
                {
                    temp[j] = 0;
                }
            }
            int res = temp[0];
            vector<int>maxi(temp.size());
            maxi[0] = temp[0];
            for(int j = 1 ; j < nums.size(); j++)
            {
                maxi[j] = max(maxi[j - 1] + temp[j], temp[j]);
                res = max(res,maxi[j]);
            }

            if(i == 0)
            {
                ans = max(ans, mp[k]);
            }
            else
            {
                ans = max(ans,mp[k] + res);
            }
        }
        return ans;
    }
};
