class Solution {
public:
    long long flowerGame(int n, int m)
    {
        using ll = long long;
        ll ans = ((ll)((n + 2 - 1) / 2) * (ll)(m / 2)) + ((ll)(n / 2) * (ll)((m + 2 - 1) / 2));
        return ans;
    }
};
