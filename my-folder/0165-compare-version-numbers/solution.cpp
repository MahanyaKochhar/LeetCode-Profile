class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        vector<int>v1s,v2s;
        auto update = [](string v1,vector<int>& ls) -> void {
            string str = "";
            for(int i = 0 ; i < v1.length();i++)
            {
                if(v1[i] == '.')
                {
                    int curr = stoi(str);
                    ls.push_back(curr);
                    str = "";
                }
                else
                {
                    str.push_back(v1[i]);
                }
            }
            if(str != "")
            {
                ls.push_back(stoi(str));
            }
        };

        update(version1,v1s);
        update(version2,v2s);
        int i = 0, j = 0;
        while(i < v1s.size() || j < v2s.size())
        {
            int v1 = (i < v1s.size()) ? v1s[i] : 0;
            int v2 = (j < v2s.size()) ? v2s[j] : 0;
            if(v1 > v2)
            {
                return 1;
            }
            else if(v1 < v2)
            {
                return -1;
            }
            i++;
            j++;
        }
        return 0;
    }
};
