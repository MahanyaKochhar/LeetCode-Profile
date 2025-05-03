class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms)
    {
        auto complete = [](vector<int>primary,vector<int>secondary) -> int {
            int ans = INT_MAX;
            for(int i = 1 ; i <= 6 ; i++)
            {
                int curr = 0;
                int e = 0;
                for(int j = 0 ; j < primary.size();j++)
                {
                    if(primary[j] == i)
                    {
                        continue;
                    }
                    else if(secondary[j] == i)
                    {
                        curr++;
                    }
                    else
                    {
                        e = 1;
                        break;
                    }
                }
                if(e == 0)
                {
                    ans = min(ans,curr);
                }
            }
            return ans;
        };
        int fin = min(complete(tops,bottoms),complete(bottoms,tops));
        return fin == INT_MAX ? -1 : fin;
    }
};
