class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        using ll = long long;
        vector<int>ans(n,0);
        sort(meetings.begin(), meetings.end());
        set<int>avl;
        priority_queue<pair<ll,ll>> pq;
        for(int i = 0 ; i < n; i++)
        {
            avl.insert(i);
        }

        for(int i = 0 ; i < meetings.size() ; i++)
        {
            ll st = meetings[i][0];
            ll end = meetings[i][1];
            while(!pq.empty() && -pq.top().first <= st)
            {
                avl.insert(-pq.top().second);
                pq.pop();
            }

            if(avl.size() != 0)
            {
                int room = *(avl.begin());
                ans[room]++;
                pq.push({-end,-room});
                avl.erase(room);
            }
            else
            {
                auto poss = pq.top();
                pq.pop();
                ll time = -poss.first;
                ll room = -poss.second;
                ll dur = end - st;
                ans[room]++;
                pq.push({-(time + dur),-room});
            }
        }
        int fin = INT_MIN;
        int room = -1;
        for(int i = 0 ; i < ans.size(); i++)
        {
            if(ans[i] > fin)
            {
                fin = ans[i];
                room = i;
            }
        }
        return room;
    }
};
