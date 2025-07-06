class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive)
    {
        auto checkCode = [&] (int i) -> bool {
            string s = code[i];
            if(s == "")
            {
                return false;
            }
            for(int j = 0 ; j < s.length(); j++)
            {
               if((s[j] >= 65 && s[j] <= 90) || (s[j] >= 97 && s[j] <= 122) || (s[j] >= 48 && s[j] <= 57) || s[j] == '_')
               {
                   continue;
               }
               else
               {
                   return false;
               }
            }
            return true;
        };

        auto checkBusiness = [&](int i) -> bool {
            string s = businessLine[i];
            set<string>bus;
            bus.insert({"electronics","grocery","pharmacy","restaurant"});
            if(bus.find(s) != bus.end())
            {
                return true;
            }
            else
            {
                return false;
            }
        };
        vector<pair<string,string>>ind;
        for(int i = 0 ; i < code.size(); i++)
        {
            bool isCode = checkCode(i);
            bool isBus = checkBusiness(i);
            bool isAct = isActive[i];
            if(isCode && isBus && isAct)
            {
                ind.push_back({businessLine[i],code[i]});
            }
        }
        sort(ind.begin(),ind.end());
        vector<string>ans;
        for(int i = 0 ; i < ind.size(); i++)
        {
            ans.push_back(ind[i].second);
        }
        return ans;
    }
};
