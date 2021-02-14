class Solution {
public:
    int minOperations(string s) {
    	int l=s.length();
    	
    		int count1=0,count2=0;
    		for(int j=0;j<s.length();j++)
    		{
    			if(j%2==0)
    			{
    			if(s[j]!='0')
    			{
    				count1++;
    			}
    		}
    		else
    		{
    			if(s[j]!='1')
    				count1++;
    		}
    	}
    	for(int j=0;j<s.length();j++)
    		{
    			if(j%2==0)
    			{
    			if(s[j]!='1')
    			{
    				count2++;
    			}
    		}
    		else
    		{
    			if(s[j]!='0')
    				count2++;
    		}
    	}
    	return min(count1,count2);

    	}
        
    
};
