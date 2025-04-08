class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        auto checkUnique = [] (vector<int> v) -> int {
            set<int>s;
            for(auto x : v)
            {
                s.insert(x);
            }
            if(s.size() == v.size())
                return true;
            else
                return false;
        };
        int cnt = 0;
        while(true)
        {
            int uq = checkUnique(nums);
            if(uq)
                break;
            cnt++;
            vector<int>tmp;
            for(int i = 3 ; i < nums.size();i++)
            {
                tmp.push_back(nums[i]);
            }
            nums = tmp;
        }
        return cnt;
    }
};
