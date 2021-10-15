class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes)
    {
       vector<int>ans(barcodes.size());
       sort(barcodes.begin(),barcodes.end());
       int x=barcodes.size();
        int posse,posso;
        if(x%2==0)
        {
            
             posse=x-2;
             posso=x-1;
        }
        else
        {
             posse=x-1;
             posso=x-2;
        }
        int curr1=0;
        int curr2=1;
        map<int,int>mp;
        for(int i=0;i<barcodes.size();i++)
        {
            mp[barcodes[i]]++;
        }
        vector<pair<int,int>>p;
        for(auto x:mp)
        {
            p.push_back({x.second,x.first});
        }
        sort(p.rbegin(),p.rend());
        for(int i=0;i<p.size();i++)
        {
            int x=p[i].first;
            while(x!=0)
            {
                if(curr1<=posse)
                {
                ans[curr1]=p[i].second;
                x--;
                curr1+=2;
                }
                else
                {
                    ans[curr2]=p[i].second;
                    curr2+=2;
                    x--;
                }
            }
        }
        return ans;
    }
};
