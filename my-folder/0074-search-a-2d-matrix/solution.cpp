class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int l = -1, r = matrix.size();
        while( l + 1 < r)
        {
            int mid = (l + r ) / 2;
            if(matrix[mid][0] > target)
            {
                r = mid;
            }
            else
                l = mid;
        }
        if(r == 0)
            return false;
        else
        {
            r--;
        }
        auto it = lower_bound(matrix[r].begin() , matrix[r].end(),target);
        if(it != matrix[r].end() && *it == target)
            return true;
        else
            return false;
    }
};
