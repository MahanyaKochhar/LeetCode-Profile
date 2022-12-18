class Solution {
public:
    int similarPairs(vector<string>& words)
    {
        for(int i=0;i<words.size();i++)
        {
            set<int>s;
            for(int j=0;j<words[i].size();j++)
            {
                s.insert(words[i][j]);
            }
            string s2="";
            for(auto x:s)
            {
                s2.push_back(x);
            }
            words[i]=s2;
        }
        int cnt=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(words[i]==words[j])
                    cnt++;
            }
        }
        return cnt;
    }
};
