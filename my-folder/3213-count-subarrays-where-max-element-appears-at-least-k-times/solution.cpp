class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k)
    {
        int maxi = -1;
        long long cnt = 0;
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(maxi < nums[i])
            {
                maxi = nums[i];
            }
        }
        vector<int>idx;
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(nums[i] == maxi)
            {
                idx.push_back(i + 1);
            }
        }
        int seenSoFar = 0;
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(nums[i] == maxi)
            {
                seenSoFar++;
            }
            if(seenSoFar >= k)
            {
                cnt += idx[seenSoFar - k];
            }
        }
        return cnt;
    }
};
