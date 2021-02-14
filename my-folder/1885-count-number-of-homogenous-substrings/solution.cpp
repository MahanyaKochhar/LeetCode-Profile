class Solution {
public:
    int countHomogenous(string s) {
    	long long int l=0,r=0;
    	long long int count=0;
    	while(r!=s.length())
    	{
    		if(s[l]==s[r])
    			r++;
    		else
    		{
    			int length=r-l;
    			count=count+((length)*(length+1))/2;
                        count=count%1000000007;
    			l=r;
    		}
    	}
    	long long int fin=r-l;
    	count=count+(((fin)*(fin+1))/2);
            count=count%1000000007;
            int ans=(int)count;
        return ans;
    }
};
