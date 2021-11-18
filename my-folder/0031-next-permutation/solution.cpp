class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int idx=-1;
        for(int j=nums.size()-1;j>0;j--)
        {
            if(nums[j]>nums[j-1])
            {
              idx=j-1;
                break;
            }
            else
                continue;
        }
        if(idx==-1)
            reverse(nums.begin(),nums.end());
        else
        {
            int ans=idx;
            for(int k=nums.size()-1;k>=idx+1;k--)
            {
                if(nums[k]>nums[idx])
                {
                    swap(nums[k],nums[idx]);
                    break;
                }
            }
            auto it=nums.begin()+idx+1;
            reverse(it,nums.end());
            
        }
    }
};
