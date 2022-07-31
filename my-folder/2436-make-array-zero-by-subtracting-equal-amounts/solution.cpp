class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        int cnt=0;
        while(true)
        {
            int cy=101;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
                cy=min(cy,nums[i]);
        }
            if(cy==101)
                break;
            else
            {
                cnt++;
                for(int i=0;i<nums.size();i++)
                {
                    if(nums[i]!=0)
                        nums[i]-=cy;
                }
            }
            
        
    }
        return cnt;
    }
};
