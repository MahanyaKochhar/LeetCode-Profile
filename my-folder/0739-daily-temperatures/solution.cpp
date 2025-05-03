class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int>ans(temperatures.size(),0);
        stack<int>s;
        for(int i = 0 ; i < temperatures.size() ;i++)
        {
            while(!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                int idx = s.top();
                s.pop();
                ans[idx] = i - idx;
            }
            s.push(i);
        }
        return ans;
    }
};
