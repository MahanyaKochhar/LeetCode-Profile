class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries)
    {
        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            int node1=queries[i][0];
            int node2=queries[i][1];
            int lv=(int)log2(node1);
            int lv2=(int)log2(node2);
            if(lv<lv2)
            {
                swap(lv,lv2);
                swap(node1,node2);
            }
            int cnt=0;
            while(lv!=lv2)
            {
                node1=node1/2;
                cnt++;
                lv--;
            }
            while(node1!=node2)
            {
                cnt+=2;
                node1=node1/2;
                node2=node2/2;
            }
            ans.push_back(cnt+1);
        }
        return ans;
    }
};
