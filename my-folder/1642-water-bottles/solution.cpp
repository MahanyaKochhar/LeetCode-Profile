class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = 0;
        int empty = 0;
        while(numBottles != 0)
        {
            ans += numBottles;
            int tmp = numBottles;
            numBottles = (tmp + empty) / numExchange;
            empty = (tmp + empty) % numExchange;
        }
        return ans;
    }
};
