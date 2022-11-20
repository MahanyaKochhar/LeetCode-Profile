/**
 * @param {number[][]} roads
 * @param {number} seats
 * @return {number}
 */
var subtree_sz=[];
var ans=[];
function dfs(adjlist,seats,node,pv)
{
    subtree_sz[node]=1;
    for(let i=0;i<adjlist[node].length;i++)
    {
        if(adjlist[node][i]==pv)
            continue;
        dfs(adjlist,seats,adjlist[node][i],node);
        subtree_sz[node]+=subtree_sz[adjlist[node][i]];
        ans[node]+=ans[adjlist[node][i]];
    }
    if(node!=0)
        ans[node]+=Math.ceil(subtree_sz[node]/seats);
    
}
var minimumFuelCost = function(roads, seats)
{
    subtree_sz=[];
    const adjlist=[];
    for(let i=0;i<=roads.length;i++)
    {
        adjlist[i]=[];
        subtree_sz[i]=0;
        ans[i]=0;
    }
    for(let i=0;i<roads.length;i++)
    {
        let l1=roads[i][0];
        let l2=roads[i][1];
        adjlist[l1].push(l2);
        adjlist[l2].push(l1);
    }
    dfs(adjlist,seats,0,-1);
    return ans[0];
};
