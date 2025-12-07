class Solution {
public:
    int countOdds(int low, int high)
    {
        int rCnt = (high + 2 - 1) / 2;
        int lCnt = low / 2;
        return rCnt - lCnt;
    }
};
