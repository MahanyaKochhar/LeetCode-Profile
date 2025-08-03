class Solution {
public:
    int minTime(string s, vector<int>& order, int k)
    {
        using ll = long long;
        ll total = (order.size() * (order.size() + 1)) / 2;
        if(k > total)
        {
            return -1;
        }
        ll l = -1, r = order.size() - 1;
        auto good = [&](int m)-> bool {
            ll invalid = 0;
            string upd = s;
            for(int i = 0 ; i <= m ; i++)
            {
                upd[order[i]] = '*';
            }
            ll cnt = 0;
            for(int i = 0 ; i < upd.length(); i++)
            {
                if(upd[i] == '*')
                {
                    invalid += (cnt * (cnt + 1) / 2);
                    cnt = 0;
                }
                else
                {
                    cnt++;
                }
            }
            invalid += (cnt * (cnt + 1) / 2);
            ll valid = total - invalid;
            return valid >= k ? true : false;
        };
        
        while(l + 1 < r)
        {
            int mid = (l + r) / 2;
            if(good(mid))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return r;
    }
};
