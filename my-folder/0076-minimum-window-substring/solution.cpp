class Solution {
public:
    string minWindow(string s, string t)
    {
        vector<int>fq(123,0);
        int l = 0;
        int ans = INT_MAX;
        int lidx, ridx;
        for(int i = 0 ; i < t.length();i++)
        {
            fq[t[i]]++;
        }

        auto checkIfValid = [&] () -> bool {
            int e = 0;
            for(int i = 0 ; i < fq.size();i++)
            {
                if(fq[i] > 0)
                {
                    e = 1;
                    break;
                }
            }
            return e == 0 ? true : false;
        };

        for(int r = 0 ; r < s.length(); r++)
        {
            fq[s[r]]--;
            while(l <= r && fq[s[l]] < 0)
            {
                fq[s[l]]++;
                l++;
            }
            bool valid = checkIfValid();
            if(valid)
            {
                if(r - l + 1 < ans)
                {
                    ans = min(ans, r - l + 1);
                    lidx = l;
                    ridx = r;
                }
            }
        }

        return ans == INT_MAX ? "" : s.substr(lidx, ridx - lidx + 1);


    }
};
