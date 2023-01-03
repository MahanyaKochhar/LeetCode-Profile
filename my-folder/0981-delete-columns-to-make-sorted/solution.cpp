class Solution {
public:
    int minDeletionSize(vector<string>& strs)
    {
        char mat[101][1001];
        for(int i=0;i<strs.size();i++)
        {
            for(int j=0;j<strs[i].length();j++)
            {
                mat[i][j]=strs[i][j];
            }
        }
        int cnt=0;
        for(int j=0;j<strs[0].length();j++)
        {
            int e=0;
            for(int i=0;i<strs.size();i++)
            {
                if(i==0)
                    continue;
                if(mat[i][j]>=mat[i-1][j])
                    continue;
                else
                    e=1;
            }
            if(e==1)
                cnt++;
        }
        return cnt;
    }
};
