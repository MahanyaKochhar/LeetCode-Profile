class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int start_pt=0;
        while(start_pt<gas.size())
        {
            int j=start_pt;
            int cnt=0;
            int curr_gas=0;
            while(cnt<gas.size())
            {
                curr_gas+=gas[j%gas.size()]-cost[j%gas.size()];
                if(curr_gas>=0)
                {
                    cnt++;
                    j++;
                }
                else
                    break;
            }
            if(cnt==gas.size())
                return start_pt;
            else
            {
                start_pt=j+1;
            }
        }
        return -1;
    }
};
