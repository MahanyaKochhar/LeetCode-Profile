class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements)
    {
        vector<int>result(groups.size(),-1);
        vector<int> nos(1e5 + 1,INT_MAX);
        vector<bool> vis(1e5 + 1, false);
        for(int i = 0 ; i < elements.size() ; i++)
        {
            int no = elements[i];
            if(!vis[no])
            {
                vis[no] = true;
                for(int j = no ; j <= 1e5 ; j+= no)
                {
                    nos[j] = min(i,nos[j]);
                }
            }
        }
        for(int i = 0 ; i < groups.size() ; i++)
        {
            if(nos[groups[i]] != INT_MAX)
                result[i] = nos[groups[i]];
        }
        return result;
    }
};
