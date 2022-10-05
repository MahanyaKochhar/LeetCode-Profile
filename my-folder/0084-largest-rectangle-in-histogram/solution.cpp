class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
    	typedef long long int lli;
    	typedef pair<lli,lli> pi;
        stack<pi>s;
        s.push({heights[0],1});
        lli ans=0;
        for(int j=1;j<heights.size();j++)
        {
        	lli fincnt=0;
        	while(!s.empty()&&heights[j]<s.top().first)
        	{
        		lli curr=s.top().first*(s.top().second+fincnt);
        		ans=max(ans,curr);
        		lli cnt=s.top().second;
        		fincnt+=cnt;
        		s.pop();
        	}
        	s.push({heights[j],fincnt+1});
        }
        lli fincnt=0;
        while(!s.empty())
        {
        	lli curr=s.top().first*(s.top().second+fincnt);
        		ans=max(ans,curr);
        		lli cnt=s.top().second;
        		fincnt+=cnt;
        		s.pop();
        }
        return ans;
    }
};
