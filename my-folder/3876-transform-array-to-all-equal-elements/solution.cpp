class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k)
    {
        auto checkSolution = [&] (vector<int>arr,int t) -> bool {
            int cnt = 0;
            for(int i = 0 ; i < arr.size() - 1 ; i++)
            {
                if(arr[i] == t)
                {
                    continue;
                }
                else
                {
                    arr[i] *= -1;
                    arr[i + 1] *= -1;
                    cnt++;
                }
            }
            if(cnt <= k && arr[arr.size() - 1] == t)
            {
                return true;
            }
            else
            {
                return false;
            }
            
        };

        return checkSolution(nums,1) || checkSolution(nums,-1);
    }
};
