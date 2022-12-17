int binaryexp(int a,int b)
{
    int res=1;
    while(b>0)
    {
        if(b&1)
            res=res*a;
        b=b/2;
        a=a*a;
    }
    return res;
}
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<long long int>s;
        for(int i=0;i<tokens.size();i++)
        {
            if((tokens[i][0]=='+')||(tokens[i][0]=='-'&&tokens[i].length()==1)||(tokens[i][0]=='*')||(tokens[i][0]=='/'))
            {
                long long int x=s.top();

                s.pop();
                long long int y=s.top();
                s.pop();
                if(tokens[i][0]=='+')
                    s.push(x+y);
                else if(tokens[i][0]=='-'&&tokens[i].length()==1)
                    s.push(y-x);
                else if(tokens[i][0]=='*')
                    s.push(x*y);
                else
                    s.push(y/x);
            }
            else
            {
                int cnt=0;
                long long int no=0;
                for(int j=tokens[i].length()-1;j>=0;j--)
                {
                    if(tokens[i][j]=='-')
                    {
                        no=0-no;
                        continue;
                    }
                    int x=tokens[i][j]-'0';
                    no=no+x*binaryexp(10,cnt);
                    cnt++;
                }
                s.push(no);
            }
        }
        return (int)s.top();
    }
};
