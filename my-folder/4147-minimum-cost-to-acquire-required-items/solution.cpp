class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2)
    {
        using ll = long long;
        ll minCost = min(cost1,cost2);
        ll maxCost = max(cost1,cost2);
        ll minNeed = min(need1,need2);
        ll maxNeed = max(need1,need2);
        if(costBoth <= minCost)
        {
            return (ll)costBoth * (ll)maxNeed;
        }
        else
        {
            ll poss = (ll)cost1 * (ll)need1 + (ll)cost2 * (ll)need2;
            ll part1 = minNeed * costBoth;
            ll rem1 = need1 - minNeed;
            ll rem2 = need2 - minNeed;
            return min(poss,part1 + min(rem1 * cost1 + rem2 * cost2 , costBoth * rem1 + costBoth * rem2));
        }
        return 0;
    }
};
