class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel)
    {
        int cntM = 0 , cntP = 0 , cntG = 0;
        int idM = -1 , idP = -1 , idG = -1;
        for(int i = 0 ; i < garbage.size() ; i++)
        {
            for(int j = 0 ; j < garbage[i].length() ; j++)
            {
                if(garbage[i][j] == 'M')
                {
                    cntM++;
                    idM = max(idM, i);
                }
                else if(garbage[i][j] == 'P')
                {
                    cntP++;
                    idP = max(idP,i);
                }
                else
                {
                    cntG++;
                    idG = max(idG, i);
                }
            }
        }
        for(int i = 0 ; i < travel.size() ; i++)
        {
            travel[i] += (i > 0) ? travel[i - 1] : 0;
        }
        int ans = cntM + cntP + cntG;
        if(idM != -1 && idM != 0)
            ans += travel[idM - 1];
        if(idP != -1 && idP != 0 )
            ans += travel[idP - 1];
        if(idG != -1 && idG != 0)
            ans += travel[idG - 1];
        return ans;
    }
};
