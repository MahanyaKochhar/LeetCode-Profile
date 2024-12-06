class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum)
    {
        set<int>s;
        for(auto x : banned)
        {
            s.insert(x);
        }
        int sum = 0;
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(i + sum <= maxSum)
            {
                if(!s.contains(i))
                {
                    sum += i;
                    cnt++;
                }
            }
            else
            {
                break;
            }
        }
        return cnt;
    }
};
