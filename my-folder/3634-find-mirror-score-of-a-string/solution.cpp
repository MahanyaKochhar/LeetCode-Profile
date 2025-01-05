class Solution {
public:
    long long calculateScore(string s)
    {
        map<int,priority_queue<int>>mp;
        long long score = 0;
        for(int i = 0 ; i < s.length() ; i++)
        {
            int mirror = 'z' - ( s[i] - 'a');
            if(mp.contains(mirror) && mp[mirror].size() > 0)
            {
                score += (i - (mp[mirror].top()));
                mp[mirror].pop();
            }
            else
            {
                mp[s[i]].push(i);
            }
        }
        return score;
    }
};
