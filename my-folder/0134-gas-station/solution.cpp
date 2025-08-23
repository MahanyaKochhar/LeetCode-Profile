class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int n = gas.size();
        int idx = 0,curr = 0;
        int surplus = 0;
        while(idx < n)
        {
            surplus = gas[idx] - cost[idx];
            curr = idx + 1;
            if(surplus < 0)
            {
                idx = curr;
                continue;
            }
            while(curr % n != idx && surplus + gas[curr % n] - cost[curr % n] >= 0)
            {
                surplus += gas[curr % n] - cost[curr % n];
                curr++;
            }
            if(curr % n != idx)
            {
                idx = curr + 1;
            }
            else
            {
                return idx;
            }
        }
        return -1;
    }
};
