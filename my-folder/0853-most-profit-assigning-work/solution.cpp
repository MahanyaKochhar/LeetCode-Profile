class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        vector<pair<int,int>> difficultyProfits;
        for(int i = 0 ; i < difficulty.size() ; i++)
        {
            difficultyProfits.push_back({difficulty[i],profit[i]});
        }
        sort(difficultyProfits.begin(),difficultyProfits.end());
        sort(worker.begin(),worker.end());
        int idx = 0;
        int ans = 0;
        int maxProfit = 0;
        for(int i = 0; i < worker.size(); i++)
        {
            int cap = worker[i];
            while(idx < profit.size() && difficultyProfits[idx].first <= cap)
            {
                maxProfit = max(maxProfit,difficultyProfits[idx].second);
                idx++;
            }
            ans += maxProfit;
        }
        return ans;
    }
};
