class Solution {
public:
    int findNumbers(vector<int>& nums)
    {
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int no = nums[i];
            int cnt = 0;
            while(no != 0)
            {
                no = no / 10;
                cnt++;
            }
            if(cnt % 2 == 0)
            {
                ans++;
            }
        }
        return ans;
    }
};
