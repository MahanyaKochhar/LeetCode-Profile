class Solution {
public:
    int maxPoints(vector<vector<int>>& points)
    {
        int ans=1;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                int cnt=0;
                for(int k=0;k<points.size();k++)
                {
                    int x=points[k][0];
                    int y=points[k][1];
                    if(y2-y1==0)
                    {
                        if(y==y1)
                            cnt++;
                    }
                    else if(x2-x1==0)
                    {
                        if(x==x1)
                            cnt++;
                    }
                    else
                    {
                        if((y-y1)*(x2-x1)==(y2-y1)*(x-x1))
                        cnt++;
                    }
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};
