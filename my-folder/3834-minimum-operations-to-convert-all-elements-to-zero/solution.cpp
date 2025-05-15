class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        stack<int>s;
        int ans = 0;
        for(int i = 0 ; i < nums.size();i++)
        {
            while(!s.empty() && s.top() > nums[i])
            {
                s.pop();
                ans++;
            }
            if(s.empty() || (!s.empty() && s.top() != nums[i]))
            {
                s.push(nums[i]);
            }
        }
        while(!s.empty())
        {
            int curr = s.top();
            if(curr != 0)
            {
                ans++;
            }
            s.pop();
        }
        return ans;
    }
};
