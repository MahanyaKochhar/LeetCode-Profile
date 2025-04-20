class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values)
    {
        int n = instructions.size();
        int i = 0;
        vector<bool>vis(n,false);
        long long score = 0;
        while(true)
        {
            if(i < 0 || i >= n || vis[i])
            {
                break;
            }
            if(instructions[i] == "add")
            {
                score += values[i];
                vis[i] = true;
                i += 1;
            }
            else
            {
                vis[i] = true;
                i = i + values[i];
            }    
        }
        return score;
    }
};
