bool cmp(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
     if(a.first==b.first)
     return a.second<b.second;
    else
    return (a.first < b.first); 
}
class Solution {
public:
vector<pair<int,int>>vec;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        for(int i=0;i<mat.size();i++)
        {
        int count1=0,count2=0;
        for(int j=0;j<mat[i].size();j++)
        {
        if(mat[i][j]==0)
        count1++;
        else
        count2++;
        }
        vec.push_back({count2,i});
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<int>vec1;
        for(int j=0;j<k;j++)
        {
            vec1.push_back(vec[j].second);
        }
        return vec1;
    }
};
