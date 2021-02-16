class Solution {
public:
	vector<string>stringar;
    vector<string> letterCasePermutation(string S) {
        letters(S,S.length(),"");
        return stringar;
    }
    void letters(string s,int l,string cons)
    {
    	if(l==0)
    	{
    		string a=cons;
    		reverse(a.begin(),a.end());
    		stringar.push_back(a);
    		return;
    	}
    	if(s[l-1]>=65&&s[l-1]<=90)
    	{
    		char ch=s[l-1];
    		char ch1=s[l-1]+32;
    		 letters(s,l-1,cons+ch);
    		 letters(s,l-1,cons+ch1);
    	}
    	else if((s[l-1]>=97&&s[l-1]<=122))
    	{
    		char ch=s[l-1];
    		char ch1=s[l-1]-32;
    		letters(s,l-1,cons+ch);
    		letters(s,l-1,cons+ch1);

    	}
    	else
    		letters(s,l-1,cons+s[l-1]);
    }
};
