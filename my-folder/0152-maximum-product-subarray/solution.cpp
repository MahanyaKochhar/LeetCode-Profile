class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        vector<int>maxi(nums.size());
        vector<int> mini(nums.size());
        maxi[0] = nums[0];
        mini[0] = nums[0];
        int res = maxi[0];
        for(int i = 1 ; i < nums.size(); i++)
        {
            if(nums[i] >= 0)
            {
                maxi[i] = max(nums[i], maxi[i - 1] * nums[i]);
                mini[i] = min(nums[i],mini[i - 1] * nums[i]);
            }
            else
            {
                maxi[i] = max(nums[i],mini[i - 1] * nums[i]);
                mini[i] = min(nums[i], maxi[i - 1] * nums[i]);
            }
            res = max(res,maxi[i]);
        }
        return res;
    }
};
