class Solution {
public:
    int jump(vector<int>& nums)
    {
        int jumps = 0;
        int steps = 0, maxRange = 0;
        for(int i = 0 ; i < nums.size() - 1; i++)
        {
            if(steps == 0)
            {
                jumps++;
                maxRange = max(maxRange,i + nums[i]);
                steps = maxRange - i;
            }
            else
            {
                maxRange = max(maxRange,i + nums[i]);
            }
            steps--;
        }
        return jumps;
    }
};
