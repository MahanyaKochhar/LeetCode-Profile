class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        sort(nums.begin(),nums.end());
        int l = -1 , r = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == val && l == -1)
            {
                l = i;
                r = i;
            }
            else if(nums[i] == val)
            {
                r = i;
            }
        }
        if(l == -1)
        {
            return nums.size();
        }
        int k = nums.size() - (r - l + 1);
        if(l != -1)
        {
            for(int j = r + 1; j < nums.size() ; j++)
            {
                nums[l] = nums[j];
                l++;
            }
        }
        // for(int i = k ; i < nums.size() ; i++)
        // {
        //     nums[i] = -1;
        // }
        return k;
    }
};
