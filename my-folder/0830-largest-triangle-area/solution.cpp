class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points)
    {
        double ans = 0;
        for(int i = 0 ; i < points.size();i++)
        {
            for(int j = i + 1 ; j < points.size();j++)
            {
                for(int k = j + 1 ; k < points.size();k++)
                {
                    double d1 = sqrt((points[j][0] - points[i][0]) * (points[j][0] - points[i][0])  + (points[j][1] - points[i][1]) * (points[j][1] - points[i][1]));
                    double d2 = sqrt((points[j][0] - points[k][0]) * (points[j][0] - points[k][0])  + (points[j][1] - points[k][1]) * (points[j][1] - points[k][1]));
                    double d3 = sqrt((points[i][0] - points[k][0]) * (points[i][0] - points[k][0])  + (points[i][1] - points[k][1]) * (points[i][1] - points[k][1]));
                    double s = (d1 + d2 + d3) / 2;
                    if(s - d1 > 0 && s - d2 > 0 && s - d3 > 0)
                    {
                        double fin = sqrt(s * (s - d1) * (s - d2) * (s - d3));
                        ans = max(ans,fin);
                    }
                }
            }
        }
        return ans;
    }
};
