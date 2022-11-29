class RandomizedSet {
public:
    map<int,int>mp;
    vector<int>nums;
    RandomizedSet()
    {
        
    }
    
    bool insert(int val)
    {
        if(mp.find(val)==mp.end())
        {
            nums.push_back(val);
            mp[val]=nums.size()-1;
            return true;
        }
        else
            return false;
    }
    
    bool remove(int val)
    {
        if(mp.find(val)==mp.end())
            return false;
        else
        {
            int lt=nums[nums.size()-1];
            int pos=mp[val];
            mp[lt]=pos;
            mp.erase(val);
            nums[pos]=lt;
            nums.pop_back();
            return true;
        }
    }
    int getRandom()
    {
        int idx=(rand())%nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
