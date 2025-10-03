class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int empty = 0;
        int ans = 0;
        while(numBottles != 0 || empty >= numExchange)
        {
            if(empty >= numExchange)
            {
                empty -= numExchange;
                numExchange++;
                numBottles++;
            }
            else if(numBottles > 0)
            {
                ans += numBottles;
                empty += numBottles;
                numBottles = 0;
            }
        }
        return ans;
    }
};
