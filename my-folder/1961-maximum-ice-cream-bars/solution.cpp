class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins)
    {
        sort(costs.begin(),costs.end());
        int cnt=0;
        long long curr=0;
        for(int i=0;i<costs.size();i++)
        {
            if(curr+costs[i]>coins)
                return cnt;
            else
            {
                cnt++;
                curr+=costs[i];
            }
        }
        return cnt;
    }
};
