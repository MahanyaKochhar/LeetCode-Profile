class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m)
    {
        vector<int>cnt(1e5 + 1,0);
        vector<bool>taken(arrivals.size(),false);
        int ans = 0;
        for(int i = 0 ; i < w ; i++)
        {
            int item = arrivals[i];
            if(cnt[item] + 1 <= m)
            {
                taken[i] = true;
                cnt[item]++;
            }
            else
            {
                ans++;
            }
        }
        for(int i = w; i < arrivals.size();i++)
        {
            int item = arrivals[i];
            if(taken[i - w])
            {
                cnt[arrivals[i - w]]--;
            }
            if(cnt[item] + 1 <= m)
            {
                taken[i] = true;
                cnt[item]++;
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }
};
