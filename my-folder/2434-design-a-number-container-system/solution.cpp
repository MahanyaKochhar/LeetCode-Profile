class NumberContainers {
private:
unordered_map<int,int> mp;
unordered_map<int,set<int>> noToIdxMap;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp.find(index) == mp.end())
        {
            mp[index] = number;
            noToIdxMap[number].insert(index);
        }
        else
        {
            int prev = mp[index];
            mp[index] = number;
            noToIdxMap[prev].erase(index);
            if(noToIdxMap[prev].empty())
            {
                noToIdxMap.erase(prev);
            }
            noToIdxMap[number].insert(index);
        }
    }
    
    int find(int number) {
        if(noToIdxMap[number].size())
        {
            return *noToIdxMap[number].begin();
        }
        else
        {
            return -1;
        }
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
