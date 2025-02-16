class Solution {
public:
    long long maxWeight(vector<int>& pizzas)
    {
        sort(pizzas.rbegin(),pizzas.rend());
        int days = pizzas.size() / 4;
        int od = (days + 2 - 1) / 2;
        int ev = days / 2;
        long long ans = 0;
        for(int j = 0; j < od ; j++)
        {
            ans += pizzas[j];
        }
        int cnt = 0;
        int idx = od + 1;
        while(cnt != ev)
        {
            ans += pizzas[idx];
            idx += 2;
            cnt += 1;
        }
        return ans;
    }
};
