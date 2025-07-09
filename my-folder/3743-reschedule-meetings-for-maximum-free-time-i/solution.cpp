class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime)
    {
        vector<int>gaps(startTime.size() + 1);
        for(int i = 0 ; i < gaps.size();i++)
        {
            if(i == 0)
            {
                gaps[i] = startTime[i] - 0;
                continue;
            }
            else if(i == startTime.size())
            {
                gaps[i] = eventTime - endTime[i - 1];
            }
            else
            {
                gaps[i] = startTime[i] - endTime[i - 1];
            }
        }
        int ans = 0;
        for(int i = 0 ; i <= k ; i++)
        {
            ans += gaps[i];
        }
        int fin = ans;
        for(int i = k + 1 ; i < gaps.size(); i++)
        {
            ans -= gaps[i - k - 1];
            ans += gaps[i];
            fin = max(ans,fin);
        }
        return fin;
    }
};
