class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        vector<vector<int>>pre(matrix.size()+1,vector<int>(matrix[0].size()+1));
        for(int i=1;i<=matrix.size();i++)
        {
            for(int j=1;j<=matrix[0].size();j++)
            {
                pre[i][j]=matrix[i-1][j-1]+pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1];
            }
        }
        int cnt=0;
        for(int i=1;i<=matrix.size();i++)
        {
            for(int j=1;j<=matrix[0].size();j++)
            {
                for(int k=i;k<=matrix.size();k++)
                {
                    for(int l=j;l<=matrix[0].size();l++)
                    {
                        int ans=pre[k][l]-pre[k][j-1]-pre[i-1][l]+pre[i-1][j-1];
                        if(ans==target)
                            cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
