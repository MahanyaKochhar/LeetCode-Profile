class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        sort(meetings.begin(),meetings.end());
        vector<int>ans(n,0);
        vector<long long>rooms(n,0);
        for(int i = 0 ; i < meetings.size();i++)
        {
            int pick = -1;
            for(int j = 0 ; j < rooms.size();j++)
            {
                if(meetings[i][0] >= rooms[j])
                {
                    pick = j;
                    break;
                }
            }
            if(pick != -1)
            {
                ans[pick]++;
                rooms[pick] = meetings[i][1];
            }
            else
            {
                long long mini = 1e11;
                for(int j = 0 ; j < rooms.size();j++)
                {
                    if(rooms[j] < mini)
                    {
                        mini = rooms[j];
                        pick = j;
                    }
                }
                ans[pick]++;
                rooms[pick] = mini + meetings[i][1] - meetings[i][0];
            }
        }
        int fin = -1;
        int room = 0;
        for(int i = 0 ; i < ans.size();i++)
        {
            if(ans[i] > fin)
            {
                fin = ans[i];
                room = i;
            }
        }
        return room;
    }
};
