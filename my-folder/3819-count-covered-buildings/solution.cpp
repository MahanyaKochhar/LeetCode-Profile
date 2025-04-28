class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings)
    {
        int maxiL = -1,maxiM = -1;
        for(int i = 0 ; i < buildings.size(); i++)
        {
            int l = buildings[i][0];
            int m = buildings[i][1];
            maxiL = max(maxiL,l);
            maxiM = max(maxiM,m);
        }
        vector<vector<int>>adjList1(maxiL + 1,vector<int>(2,-1));
        vector<vector<int>>adjList2(maxiM + 1,vector<int>(2,-1));
        int cnt = 0;
        for(int i = 0 ; i < buildings.size(); i++)
        {
            int l = buildings[i][0];
            int m = buildings[i][1];
            vector<int>& v1 = adjList1[l];
            vector<int>& v2 = adjList2[m];
            if(v1[0] > m || v1[0] == -1)
            {
                v1[0] = m;
            }
            if(v1[1] < m || v1[1] == -1)
            {
                v1[1] = m;
            }
            if(v2[0] > l || v2[0] == -1)
            {
                v2[0] = l;
            }
            if(v2[1] < l || v2[1] == -1)
            {
                v2[1] = l;
            }
        }
        for(int i = 0 ; i < buildings.size();i++)
        {
            int l = buildings[i][0];
            int m = buildings[i][1];
            int fV = adjList1[l][0];
            int lV = adjList1[l][1];
            int fV2 = adjList2[m][0];
            int lV2 = adjList2[m][1];
            if(m == fV || m == lV || l == fV2 || l == lV2)
            {
                continue;
            }
            cnt++;
        }
        return cnt;
    }
};
