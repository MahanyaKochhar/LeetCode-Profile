class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions)
    {
        int d = -1,a = -1;
        for(auto& x : dimensions)
        {
            int u = x[0];
            int v = x[1];
            if(u * u + v * v >= d)
            {
                if( d == u * u + v * v && u * v > a)
                {
                    a = u * v;
                }
                else if(d != u * u + v * v)
                {
                    d = u * u + v * v;
                    a = u * v;
                }
            }
        }
        return a;
    }
};
