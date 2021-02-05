class Solution {
public:
   
    int count=0;
    int countArrangement(int n) {
         vector<bool>visited(16);
        noofpermutations(1,n,visited);
        return count;
    }
    void noofpermutations(int pos,int n,vector<bool>vis)
    {
        if(pos>n)
            count++;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&((pos%i==0)||(i%pos==0)))
            {
               vis[i]=true;
               noofpermutations(pos+1,n,vis);
                vis[i]=false;
            }
        }
    }
};
