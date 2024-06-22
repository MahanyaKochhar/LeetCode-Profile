class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes)
    {
        int ans = 0;
        for(int i = 0 ; i < customers.size() ; i++)
        {
            if(grumpy[i] == 0)
            {
                ans += customers[i];
            }
        }
        for(int i = 0 ; i < minutes; i++)
        {
            if(grumpy[i])
            {
                ans += customers[i];
            }
        }
        int curr = ans;
        for(int j = minutes; j < customers.size() ; j++)
        {
            if(grumpy[j - minutes])
            {
                curr -= customers[j - minutes];
            }
            if(grumpy[j])
            {
                curr += customers[j];
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};
