class Solution {
public:
    int minimumPairRemoval(vector<int>& nums)
    {
        int cnt = 0;
        auto checkIfIncreasing = [&] () -> int {
            int e = 1;
            for(int i = 1 ; i < nums.size() ; i++)
            {
                if(nums[i] >= nums[i - 1])
                {
                    continue;
                } 
                else
                {
                    e = 0;
                    break;
                }
            }
            return e;
        };

        while(true)
        {
            int ans = checkIfIncreasing();
            if(ans == 1)
                break;
            cnt++;
            int idx = 0;
            int sum = 1e5;
            for(int i = 1 ; i < nums.size();i++)
            {
                if(nums[i] + nums[i - 1] < sum)
                {
                    sum = nums[i] + nums[i - 1];
                    idx = i;
                }    
            }
            vector<int> curr ;
            for(int i = 0 ; i < nums.size(); i++)
            {
                if(idx - 1 == i)
                {
                    continue;
                }    
                if(idx == i)
                {
                    curr.push_back(sum);
                }
                else
                {
                    curr.push_back(nums[i]);
                }
            }
            
            nums = curr;
        }
        return cnt;
    }
};
