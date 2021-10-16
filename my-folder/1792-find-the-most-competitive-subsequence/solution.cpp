class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k)
    {
        stack<int>s;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        { 
            if(s.empty()||(s.top()<=nums[i]&&s.size()!=k))
            {
                s.push(nums[i]);
                continue;
            }
            while(!s.empty()&&s.top()>nums[i]&&s.size()+n-i>k)
            {
                s.pop();
            }
            if(s.size()!=k)
            s.push(nums[i]);
            
        }
        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
