class TaskManager {
public:
    set<pair<int,int>>s;
    vector<pair<int,int>>mp;
    TaskManager(vector<vector<int>>& tasks) {
        mp.resize(1e5 + 1);
        for(auto x : tasks)
        {
            int user = x[0];
            int id = x[1];
            int priority = x[2];
            s.insert({priority,id});
            mp[id] = {priority,user};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {priority,userId};
        s.insert({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int ex = mp[taskId].first;
        mp[taskId].first = newPriority;
        s.erase({ex,taskId});
        s.insert({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        int ex = mp[taskId].first;
        s.erase({ex,taskId});
    }
    
    int execTop() {
        if(s.size() == 0)
        {
            return -1;
        }
        pair<int,int> p = *(s.rbegin());
        int id = p.second;
        rmv(id);
        return mp[id].second;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
