class Solution {
public:
	vector<int> adjlist[100];
	vector<bool>visited;
	vector<bool>colour;
	int e=0;
    bool isBipartite(vector<vector<int>>& graph) {
    	for(int i=0;i<graph.size();i++)
    	{
    		for(int j=0;j<graph[i].size();j++)
    		{
    			adjlist[i].push_back(graph[i][j]);
    			adjlist[graph[i][j]].push_back(i);
    		}
    	}
            visited.resize(100);
            colour.resize(100);
            for(int j=0;j<graph.size();j++)
            {
             if(!visited[j])
    	bipart(j,true);
            }
    	if(e==1)
    		return false;
    	else
    		return true;

        
    }
    void bipart(int node,bool col)
    {
    	
    		visited[node]=true;
            colour[node]=col;
    		for(auto x:adjlist[node])
    		{
    			if(!visited[x])
    		bipart(x,!col);
    	if(visited[x])
    	{
    		if(col==colour[x])
    			e=1;
    	}
    	}
    }
};
