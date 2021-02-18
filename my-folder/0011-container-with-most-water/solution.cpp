class Solution {
public:
    int maxArea(vector<int>& a) {
    	int ans=INT_MIN;
    	int l=0,r=a.size()-1;
    	while(l<r)
    	{
    		ans=max(ans,min(a[l],a[r])*(r-l));
    		int val=min(a[l],a[r]);
            if(a[l]==a[r])
            {
                if(a[l+1]>val)
                {
                    if(a[r-1]>val)
                    {
                        if(a[l+1]>a[r-1])
                            l++;
                        else
                            r--;
                    }
                    else
                        l++;
                    continue;
                }
                else
                {
                    if(a[r-1]>val)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                        r--;
                    }
                    continue;
                }
                
            }
    		if(val==a[l])
    		{
                
    			if(a[l+1]>a[l])
    			{
    				l++;
    				continue;
    			}
            
    			else
                {
                    l++;
                    
                }
    		}
    		else if(val==a[r])
    		{
                
    			if(a[r-1]>a[r])
    			{
    				r--;
    			}
    			else
                {
                    
                    r--;
                }
    		}
    	}
    	return ans;
    }
};
