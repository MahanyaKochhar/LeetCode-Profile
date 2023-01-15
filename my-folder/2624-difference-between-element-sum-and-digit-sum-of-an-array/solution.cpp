class Solution {
public:
    int differenceOfSum(vector<int>& nums)
    {
        int t_sum=0;
        int d_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            t_sum+=nums[i];
            int no=nums[i];
            while(no!=0)
            {
                d_sum+=no%10;
                no=no/10;
            }
        }
        return abs(t_sum-d_sum);
    }
};
