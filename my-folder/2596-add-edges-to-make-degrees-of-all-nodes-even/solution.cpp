class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges)
    {
    	set<pair<int,int>>s;
    	vector<vector<int>>adjlist(n+1);
        for(int i=0;i<edges.size();i++)
        {
        	if(edges[i][0]<edges[i][1])
        		s.insert({edges[i][0],edges[i][1]});
        	else
        		s.insert({edges[i][1],edges[i][0]});
        	adjlist[edges[i][0]].push_back(edges[i][1]);
        	adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>nodes;
        for(int i=1;i<=n;i++)
        {
        	if(adjlist[i].size()%2!=0)
        	{
        		nodes.push_back(i);
        	}
        }
        if(nodes.size()>4||nodes.size()%2!=0)
        	return false;
        else
        {
        	if(nodes.size()==0)
        		return true;
        	if(nodes.size()==2)
        	{
        		if(s.find({nodes[0],nodes[1]})==s.end())
        			return true;
        		else
        		{
        			for(int i=1;i<=n;i++)
        			{
        				if(adjlist[i].size()%2==0)
        				{
        					int mini=min(i,nodes[0]);
        					int maxi=max(i,nodes[0]);
        					int mini2=min(i,nodes[1]);
        					int maxi2=max(i,nodes[1]);
        					if(s.find({mini,maxi})==s.end()&&s.find({mini2,maxi2})==s.end())
        						return true;
        				}
        			}
        			return false;
        		}

        	}
        	if(nodes.size()==4)
        	{
        		if(s.find({nodes[0],nodes[1]})==s.end()&&s.find({nodes[2],nodes[3]})==s.end())
        			return true;
        		if(s.find({nodes[0],nodes[2]})==s.end()&&s.find({nodes[1],nodes[3]})==s.end())
        			return true;
        		if(s.find({nodes[0],nodes[3]})==s.end()&&s.find({nodes[1],nodes[2]})==s.end())
        			return true;
        		return false;
        	}
        }
        return true;
    }
    };
