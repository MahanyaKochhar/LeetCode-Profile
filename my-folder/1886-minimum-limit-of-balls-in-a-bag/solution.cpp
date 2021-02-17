class Solution {

public:
	bool good( int value,vector<int>& nums, int maxOperations)
	{
		int count=0;
		for(auto x:nums)
		{
			if(x<=value)
				continue;
			else
			{
				count=count+x/value;
				if(x%value==0)
					count--;
			}

		}
		if(count<=maxOperations)
			return true;
		else
			return false;
	}
    int minimumSize(vector<int>& nums, int maxOperations) {
    	 int l=0,r=1e9+1;
    	 
    	while(l+1<r)
    	{
            int mid=(l+r)/2;
    		if(good(mid,nums,maxOperations))
    			r=mid;
    		else
    			l=mid;
    	}
    	return r;

        
    }
};
