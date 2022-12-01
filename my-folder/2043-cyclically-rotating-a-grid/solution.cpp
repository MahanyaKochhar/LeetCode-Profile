vector<vector<int>>ans(301,vector<int>(301,0));
void cyclic_shift(int k,vector<vector<int>>&grid,int l_r1,int l_c1,int l_r2,int l_c2,int l_r3,int l_c3,int l_r4,int l_c4)
{
	vector<int>temp;
	int idx=0;
	for(int j=l_r1;j<=l_r2;j++)
	{
		temp.push_back(grid[j][l_c1]);
	}
	for(int j=l_c1+1;j<=l_c3;j++)
	{
		temp.push_back(grid[l_r2][j]);
	}
	for(int j=l_r3-1;j>=l_r4;j--)
	{
		temp.push_back(grid[j][l_c3]);
	}
	for(int j=l_c4-1;j>l_c1;j--)
	{
		temp.push_back(grid[l_r4][j]);
	}
	k=k%temp.size();
	rotate(temp.begin(),temp.begin()+temp.size()-k,temp.end());
	for(int j=l_r1;j<=l_r2;j++)
	{
		ans[j][l_c1]=temp[idx];
		idx++;
	}
	for(int j=l_c1+1;j<=l_c3;j++)
	{
		ans[l_r2][j]=temp[idx];
		idx++;
	}
	for(int j=l_r3-1;j>=l_r4;j--)
	{
		ans[j][l_c3]=temp[idx];
		idx++;
	}
	for(int j=l_c4-1;j>l_c1;j--)
	{
		ans[l_r4][j]=temp[idx];
		idx++;
	}
}
class Solution {
public:
	
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k)
    {
    	int pos=min(grid.size(),grid[0].size())/2;
        // vector<vector<int>>ans(grid.size(),vector<int>(grid[0].size()));
        int l_r1=0,l_c1=0,l_r2=grid.size()-1,l_c2=0,l_r3=grid.size()-1,l_c3=grid[0].size()-1,l_r4=0,l_c4=grid[0].size()-1;
        int cnt=0;
        while(cnt<pos)
        {
        	cyclic_shift(k,grid,l_r1,l_c1,l_r2,l_c2,l_r3,l_c3,l_r4,l_c4);
        	l_r1++;
        	l_c1++;
        	l_r2--;
        	l_c2++;
        	l_r3--;
        	l_c3--;
        	l_r4++;
        	l_c4--;
        	cnt++;
        }
        vector<vector<int>>fin(grid.size(),vector<int>(grid[0].size()));
        for(int i=0;i<grid.size();i++)
        {
        	for(int j=0;j<grid[i].size();j++)
        	{
        		fin[i][j]=ans[i][j];
        	}
        }
        return fin;
    }
};
