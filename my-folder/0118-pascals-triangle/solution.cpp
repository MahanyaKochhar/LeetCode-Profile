class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>>ans;
        vector<int>beg;
        beg.push_back(1);
        ans.push_back(beg);
        for(int i=2;i<=numRows;i++)
        {
            vector<int>beg;
            for(int j=0;j<i;j++)
            {
                if(j==0||j==i-1)
                    beg.push_back(1);
                else
                    beg.push_back(ans[i-2][j]+ans[i-2][j-1]);
                    
            }
            ans.push_back(beg);
        }
    return ans;
    }
};
