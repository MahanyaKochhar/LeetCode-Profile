class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words)
    {
        auto compute = [&] (int idx1,int idx2) -> int {
            int i = 0;
            while(i < words[idx1].length() && i < words[idx2].length() && words[idx1][i] == words[idx2][i])
            {
                i++;
            }
            return i;
        };
        vector<int>ans(words.size());
        vector<int>lcp(words.size());
        for(int i = 1 ; i < words.size(); i++)
        {
            lcp[i] = compute(i,i - 1);
        }
        vector<int>pre(words.size(),0);
        vector<int>suff(words.size(),0);
        for(int i = 1; i < words.size();i++)
        {
            pre[i] = max(pre[i - 1],lcp[i]);
            suff[words.size() - 1 - i] = max(suff[words.size() - i],lcp[words.size()- i]);
        }

        for(int i = 0 ; i < words.size();i++)
        {
            int lMax = i - 1 >= 0 ? pre[i - 1] : 0;
            int rMax = i + 1 < words.size() ? suff[i + 1] : 0;
            int fin = max(lMax,rMax);
            if(i - 1 >= 0 && i + 1 < words.size())
            {
                fin = max(fin,compute(i - 1,i + 1));
            }
            ans[i] = fin;
        }
        return ans;
        
    }
};
