class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int idx=0,idx2=0;
        while(true)
        {
            idx=nums[idx];
            idx2=nums[nums[idx2]];
            if(idx==idx2)
                break;
        }
        int idx3=0;
        while(true)
        {
            idx3=nums[idx3];
            idx2=nums[idx2];
            if(idx3==idx2)
                break;
        }
        return idx3;
    }
};
