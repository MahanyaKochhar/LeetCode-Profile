class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int steps = 0;
        for(int i = 0 ; i < nums.size() -1 ; i++)
        {
            steps = max(steps , nums[i]);
            if(steps == 0)
                return false;
            steps--;
        }
        return true;
    }
};
