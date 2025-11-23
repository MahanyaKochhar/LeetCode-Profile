class Solution {
public:
    int maxSumDivThree(vector<int>& nums)
    {
        vector<vector<int>>divs(3);
        int sum = 0;
        for(int i = 0 ; i < nums.size(); i++)
        {
            int div = nums[i] % 3;
            sum += nums[i];
            divs[div].push_back(nums[i]);
        }
        sort(divs[1].begin(),divs[1].end());
        sort(divs[2].begin(),divs[2].end());
        int remove = 0;
        if(sum % 3 == 0)
        {
            remove = 0;
        }
        else if(sum % 3 == 1)
        {
            int mini = INT_MAX;
            if(divs[1].size() > 0)
            {
                mini = min(mini,divs[1][0]);
            }
            if(divs[2].size() > 1)
            {
                mini = min(mini,divs[2][0] + divs[2][1]);
            }
            remove = mini;
        }
        else
        {
            int mini = INT_MAX;
            if(divs[2].size() > 0)
            {
                mini = min(mini,divs[2][0]);
            }
            if(divs[1].size() > 1)
            {
                mini = min(mini,divs[1][0] + divs[1][1]);
            }
            remove = mini;
        }
        return sum - remove;
    }
};
