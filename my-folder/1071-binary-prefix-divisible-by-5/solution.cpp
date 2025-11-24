class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums)
    {
        vector<bool>ans;
        int no = 0;
        for(int i = 0 ; i < nums.size(); i++)
        {
            no = ((2 * no) + nums[i]) % 5;
            if(no == 0)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};
