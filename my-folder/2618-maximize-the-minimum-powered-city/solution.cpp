class Solution {
public:
    long long maxPower(vector<int>& stations, int r1, int k)
    {
        vector< long long int> fenwick(stations.size() + 1);
        vector<long long int> g(stations.size() + 1);
        auto update = [&](int pos , long long val)->void
        {
            while(pos <= stations.size())
            {
                fenwick[pos] += val;
                pos += (pos&-pos);
            }
        };
        auto query =[&](int pos)->long long
        {
            long long ans = 0;
            while(pos > 0)
            {
                ans += fenwick[pos];
                pos -= (pos&-pos);
            }
            return ans;
        };
        auto update2 = [&](int pos , long long val)->void
        {
            while(pos <= stations.size())
            {
                g[pos] += val;
                pos += (pos&-pos);
            }
        };
        auto query2 =[&](int pos)->long long
        {
            long long ans = 0;
            while(pos > 0)
            {
                ans += g[pos];
                pos -= (pos&-pos);
            }
            return ans;
        };
        for(int i = 0 ; i < stations.size() ; i++)
        {
            update(i + 1,stations[i]);
        }
        long long l = 0 , r = 1e12;
        auto good = [&](long long int mid)->bool
        {
            for(int i = 1 ; i <= stations.size() ; i++)
            {
                g[i] = fenwick[i];
            }
            long long ans = 0;
            for(int i = 1 ; i <= stations.size() ; i++)
            {
                long long curr = query2(min((int)i + r1,(int)stations.size())) - query2(max(int(0),int( i - r1 - 1)));
                
                if(curr >= mid)
                    continue;
                else
                {
                    long long d = mid - curr;
                    ans += d;
                    update2(min((int)i + r1,(int)stations.size()), d);
                }
            }
            if(ans <= k)
                return true;
            else
                return false;

        };
        // return good(107374182404);
        
        while(l + 1 < r)
        {
            long long mid = (l + r) / 2;
            if(good(mid))
                l = mid;
            else
                r = mid;

        }
        return l;
    }
};
