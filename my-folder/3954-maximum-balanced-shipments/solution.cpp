class Solution {
public:
    int maxBalancedShipments(vector<int>& weight)
    {
        set<int>s;
        int cnt = 0;
        for(int i = 0 ; i < weight.size(); i++)
        {
            s.insert(weight[i]);
            if(*s.rbegin() > weight[i])
            {
                cnt++;
                s.clear();
            }
        }
        return cnt;
    }
};
