class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper)
    {
        int lbound = lower, rbound = upper;
        for(int i = 0; i < differences.size();i++)
        {
            lbound = max(lower,lbound + differences[i]);
            rbound = min(upper,rbound + differences[i]);
            if(lbound >= lower && rbound <= upper && lbound <= rbound)
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        return  rbound - lbound + 1 ;
    }
};
