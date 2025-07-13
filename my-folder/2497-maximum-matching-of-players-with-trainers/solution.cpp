class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers)
    {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int l = players.size() - 1, r = trainers.size() - 1;
        int cnt = 0;
        while(l >= 0 && r >= 0)
        {
            if(trainers[r] >= players[l])
            {
                cnt++;
                l--;
                r--;
            }
            else
            {
                l--;
            }
        }
        return cnt;
    }
};
