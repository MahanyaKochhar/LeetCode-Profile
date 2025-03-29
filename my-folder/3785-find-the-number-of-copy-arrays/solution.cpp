class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds)
    {
        int l = bounds[0][0], r = bounds[0][1];
        for(int i = 1 ; i < original.size();i++)
        {
            int d = original[i] - original[i - 1];
            l = l + d;
            r = r + d;
            l = max(l, bounds[i][0]);
            r = min(r,bounds[i][1]);
            if(r < l)
            {
                return 0;
            }
        }
        return r - l + 1;

    }
};
