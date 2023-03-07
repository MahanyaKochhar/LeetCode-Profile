class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips)
    {
        long long int l = 0, r = 1e15;
        while(l + 1 < r)
        {
            long long mid = (l + r ) / 2;
            auto good = [&](long long m)->bool
            {
                long long s = 0;
                for(int i = 0; i < time.size(); i++)
                {
                    s += (m / time[i]);
                    if(s >= totalTrips)
                        return true;
                }
                if(s >= totalTrips)
                    return true;
                else
                    return false;
            };
            if(good(mid))
                r = mid;
            else
                l = mid;
        }
        return r;
    }
};
