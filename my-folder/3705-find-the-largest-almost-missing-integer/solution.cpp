class Solution {
public:
    int largestInteger(vector<int>& nums, int k)
    {
        vector<int>ovCnt(51);
        for(int i = 0 ; i <= nums.size() - k ; i++)
        {
            int j = i + k - 1;
            vector<int>cnt(51);
            for(int l = i ; l <= j ; l++)
            {
                cnt[nums[l]] = 1;
            }
            for(int l = 0 ; l <= 50;l++)
            {
                ovCnt[l] += cnt[l];
            }
        }
        int ans = -1;
        for(int i = 0 ; i <= 50 ; i++)
        {
            if(ovCnt[i] == 1)
                ans = i;
        } 
        return ans;
    }
};
