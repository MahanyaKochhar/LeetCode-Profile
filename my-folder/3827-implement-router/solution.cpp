class Router {
public:
    queue<pair<int,pair<int,int>>>q;
    set<pair<int,pair<int,int>>>s;
    map<int,vector<int>>mp;
    int limit;
    Router(int memoryLimit)
    {
        limit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp)
    {
        auto it = s.find({source,{destination,timestamp}});
        if(it != s.end())
        {
            return false;
        }
        if(q.size() == limit)
        {
            pair<int,pair<int,int>> fr = q.front();
            q.pop();
            s.erase(fr);
            int dest = fr.second.first;
            mp[dest].erase(mp[dest].begin());
        }    
        q.push({source,{destination,timestamp}});
        s.insert({source,{destination,timestamp}});
        mp[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.size() == 0)
        {
            return {};
        }
        pair<int,pair<int,int>> fr = q.front();
        q.pop();
        s.erase(fr);
        int dest = fr.second.first;
        int ts = fr.second.second;
        mp[dest].erase(mp[dest].begin());
        return {fr.first,fr.second.first,fr.second.second};
    }
    
    int getCount(int destination, int startTime, int endTime)
    {
        if(mp.find(destination) != mp.end())
        {
            vector<int>& s = mp[destination];
            auto it1 = lower_bound(s.begin(),s.end(),startTime);
            auto it2 = upper_bound(s.begin(),s.end(),endTime);
            if(it1 == s.end() || it2 == s.begin())
            {
                return 0;
            }
            it2--;
            int idx1 = it1 - s.begin();
            int idx2 = it2 - s.begin();
            return idx2 - idx1 + 1;
        }
        else
        {
            return 0;
        }
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
