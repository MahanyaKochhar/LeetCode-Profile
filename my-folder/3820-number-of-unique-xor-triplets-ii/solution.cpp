class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums)
    {
        vector<int>poss(2048,0);
        for(int i = 0 ; i < nums.size(); i++)
        {
            for(int j = 0 ; j < nums.size(); j++)
            {
                int a = (nums[i] ^ nums[j]);
                poss[a] = 1;
            }
        }
        vector<int>ans(2048,0);
        for(int i = 0 ; i < nums.size();i++)
        {
            for(int j = 0 ; j < poss.size();j++)
            {
                if(poss[j] == 1)
                {
                    int a = (nums[i] ^ j);
                    ans[a] = 1;
                }
            }   
        }
        int cnt = 0;
        for(int i = 0 ; i < ans.size();i++)
        {
            if(ans[i] == 1)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
