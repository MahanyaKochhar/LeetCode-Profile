class Solution {
public:
    string clearStars(string s)
    {
        using pii = pair<int,int>;
        priority_queue<pii>pq;
        vector<bool>skip(s.length(),false);
        for(int i = 0 ; i < s.length();i++)
        {
            if(s[i] == '*')
            {
                skip[i] = true;
                auto x = pq.top();
                pq.pop();
                skip[x.second] = true;
            }
            else
            {
                pq.push({-(s[i] - 'a'),i});
            }
        }
        string ans = "";
        for(int i = 0 ; i < s.length();i++)
        {
            if(!skip[i])
            {
                ans.push_back(s[i]);
            }
        }
        return ans;

    }
};
