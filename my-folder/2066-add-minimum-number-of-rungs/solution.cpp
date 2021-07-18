class Solution {
public:
    int addRungs(vector<int>& rungs, int dist)
    {
        int pos=0;
        int cnt=0;
        for(int i=0;i<rungs.size();i++)
        {
            int x=rungs[i]-pos;
            if(x<=dist)
            {
                pos=rungs[i];
            }
            else
            {
                int ans=(x+dist-1)/dist -1;
                cnt+=ans;
                pos=rungs[i];
            }
        }
        return cnt;
    }
};
