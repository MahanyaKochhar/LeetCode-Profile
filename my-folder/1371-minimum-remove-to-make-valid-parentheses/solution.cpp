class Solution {
public:
    string minRemoveToMakeValid(string s) {
    	int r1=0,r2=0;
        string p="";
    	for(int k=0;k<s.length();k++)
    	{
    		if(s[k]=='(')
            {
    			r1++;
                p.push_back(s[k]);
                }
            
    		else if(s[k]==')')
    		{
    			if(r1!=0)
                {
    				r1--;
                    p.push_back(s[k]);
                }
                
    			else
                {
                    r2++;
                }
    		}
                else
                    p.push_back(s[k]);
    	}
        
    	string t2="";
        int r3=0,r4=0;
        for(int k=p.length()-1;k>=0;k--)
    	{
    		if(p[k]==')')
            {
    			r3++;
                t2.push_back(p[k]);
                }
            
    		else if(p[k]=='(')
    		{
    			if(r3!=0)
                {
    				r3--;
                    t2.push_back(p[k]);
                }
                    
    			else
                {
                    r4++;
                }
    		}
                else
                    t2.push_back(p[k]);
    	}
        reverse(t2.begin(),t2.end());
        return t2;
        

        
    }
};
