class Solution {
public:
    bool good(int v,vector<int> & position,int m)
    {
        int curr = 1;
        int x = position[0];
        for(int i = 1; i < position.size() ; i++)
        {
            int dist = position[i] - x;
            if(dist >= v)
            {
                curr++;
                x = position[i];
            }
        }
        if(curr >= m)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int maxDistance(vector<int>& position, int m)
    {
        sort(position.begin(),position.end());
        int l = 1e9 ,r = 1e9;
        for(int i = 0; i < position.size() - 1; i++)
        {
            l = min(l,position[i + 1] - position[i]);
        }
        while(l + 1 < r)
        {
            int mid = (l + r) /2;
            if(good(mid,position,m))
            {
                l = mid;
            }
            else 
            {
                r = mid;
            }
        }
        return l;
    }
};
