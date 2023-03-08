class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int maxi = -1;
        for(int i = 0 ; i < piles.size(); i++)
        {
            maxi = max(maxi,piles[i]);
        }
        int l = 0 , r = maxi;
        while(l + 1 < r)
        {
            int mid = (l + r) / 2;
            auto good = [&](int m)->bool
            {
                long long int s = 0;
                for(int i = 0 ; i < piles.size() ; i++)
                {
                    s+=(piles[i] + mid - 1) / mid;
                }
                if( s <= h)
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
