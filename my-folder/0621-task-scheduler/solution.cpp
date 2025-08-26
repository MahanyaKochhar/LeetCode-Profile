class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        map<char,int>mp;
        int total = 0;
        for(auto& x : tasks)
        {
            mp[x]++;
            total++;
        }
        priority_queue<int>pq;
        priority_queue<pair<int,int>>store;
        for(auto& [k,v] : mp)
        {
            pq.push(v);
        }
        int time = 0;
        while(total != 0)
        {
            while(!store.empty() && -store.top().first <= time)
            {
                int fq = store.top().second;
                pq.push(store.top().second);
                store.pop();
            }
            if(!pq.empty())
            {
                int fq = pq.top();
                if(fq > 1)
                {
                    store.push({-(time + n + 1),(fq - 1)});
                }
                pq.pop();
                total--;
            }
            time++;
        }
        return time;

    }
};
