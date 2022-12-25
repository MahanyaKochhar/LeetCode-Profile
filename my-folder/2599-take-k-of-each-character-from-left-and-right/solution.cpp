class Solution {
public:
    int takeCharacters(string s, int k)
    {
        int cntA=0,cntB=0,cntC=0;
        int idx=-1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a')
                cntA++;
            else if(s[i]=='b')
                cntB++;
            else
                cntC++;
            if(cntA>=k&&cntB>=k&&cntC>=k)
            {
                idx=i;
                break;
            }
        }
        if(idx==-1)
            return -1;
        int L_idx=idx+1,R_idx=0;
        int ans=L_idx;
        while(L_idx!=0)
        {
            if(s[L_idx-1]=='a')
                cntA--;
            else if(s[L_idx-1]=='b')
                cntB--;
            else
                cntC--;
            L_idx--;
            if(cntA<k||cntB<k||cntC<k)
            {
                for(int j=s.length()-R_idx-1;j>=0;j--)
                {
                    R_idx++;
                    if(s[j]=='a')
                        cntA++;
                    else if(s[j]=='b')
                        cntB++;
                    else
                        cntC++;
                    if(cntA>=k&&cntB>=k&&cntC>=k)
                    {
                        break;
                    }
                }
            }
            ans=min(ans,L_idx+R_idx);
        }
        return ans;
    }
};
