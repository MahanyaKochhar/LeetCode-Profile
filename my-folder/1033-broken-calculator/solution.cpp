class Solution {
public:
    int brokenCalc(int X, int Y) {
    	if(X>Y)
            return(X-Y);
        else
        {
        	int count=0;
        	while(X<Y)
        	{
        		if(Y%2==0)
        			Y=Y/2;
        		else
        			Y++;
        		count++;
        	}
        	count+=(X-Y);
        	return count;
            
        }
}};
