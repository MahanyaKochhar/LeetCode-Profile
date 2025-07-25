class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>s;
        int maxi = -101;
        for(auto x : nums)
        {
            maxi = max(maxi,x);
            if(x >= 0)
            {
                s.insert(x);
            }
        }
        int sum = 0;
        for(auto x : s)   
        {
            sum += x;
        }
        return s.size() != 0 ? sum : maxi;
    }
};
