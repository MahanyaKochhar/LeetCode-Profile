class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        set<int>s;
        for(auto x : nums)
        {
            s.insert(x);
        }
        if(*(s.begin()) >= k)
        {
            if(*(s.begin()) == k)
            {
                return s.size() - 1;
            }
            else
            {
                return s.size();
            }
        }
        else
        {
            return -1;
        }
    }
};
