class Solution {
public:
    int countHillValley(vector<int>& nums)
    {
        int cnt = 0;
        for(int i = 1; i < nums.size() - 1; i++)
        {
            int l = -1, r = -1;
            for(int j = i - 1; j >= 0 ; j--)
            {
                if(nums[j] != nums[i])
                {
                    l = j;
                    break;
                }
            }
            for(int j = i + 1 ; j < nums.size(); j++)
            {
                if(nums[j] != nums[i])
                {
                    r = j;
                    break;
                }
            }
            if(l == -1 || r == -1)
            {
                continue;
            }
            if((nums[i] > nums[l] && nums[i] > nums[r])  || (nums[i] < nums[l] && nums[i] < nums[r]))
            {
                if(nums[i] != nums[i - 1])
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
