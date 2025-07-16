class Solution {
public:
    int maximumLength(vector<int>& nums)
    {
        int oddCnt = 0,evenCnt = 0;
        auto maxCount = [&](bool pickOdd) -> int {
            int cnt = 0;
            for(auto& x : nums)
            {
                if(x % 2 == 1 && pickOdd)
                {
                    cnt++;
                    pickOdd = !pickOdd;
                }
                else if(x % 2 == 0 && !pickOdd)
                {
                    pickOdd = !pickOdd;
                    cnt++;
                }
            }
            return cnt;
        };

        for(auto& x : nums)
        {
            if(x % 2 == 1)
            {
                oddCnt++;
            }
            else
            {
                evenCnt++;
            }
        }

        int ans = max(maxCount(true),maxCount(false));
        ans = max(ans,max(oddCnt,evenCnt));
        return ans;
    }
};
