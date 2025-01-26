class Solution {
public:

    int getId(string id)
    {
        return stoi(id.substr(2));
    }

    static bool cmp(const vector<string> a, const vector<string>b)
    {
        if(stoi(a[1]) == stoi(b[1]))
        {
            return a[0] >= b[0];
        }
        return stoi(a[1]) <= stoi(b[1]);
    }
    void customSplit(string str, char separator,vector<string>& strings) {
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= str.size(); i++) {
        
        // If we reached the end of the word or the end of the input.
        if (str[i] == separator || i == str.size()) {
            endIndex = i;
            string temp;
            temp.append(str, startIndex, endIndex - startIndex);
            strings.push_back(temp);
            startIndex = endIndex + 1;
        }
    }

}

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events)
    {
        vector<int>cnt(numberOfUsers,0);
        vector<int>statsLast(numberOfUsers, -1);
        sort(events.begin(),events.end(),cmp);
        for(auto x: events)
        {
            vector<string> event = x;
            string type = event[0];
            if(type == "MESSAGE")
            {
                int timestamp = stoi(event[1]);
                string token = event[2];
                if(token == "ALL")
                {
                    for(int i = 0 ; i < cnt.size() ; i++)
                    {
                        cnt[i]++;
                    }
                }
                else if (token == "HERE")
                {
                    for(int i = 0 ; i < cnt.size() ; i++)
                    {
                        if(statsLast[i] <= timestamp)
                        {
                            cnt[i]++;
                        }
                    }
                }
                else
                {
                    vector<string> strings;
                    customSplit(token,' ',strings);
                    for(auto it : strings)
                    {
                        int id = getId(it);
                        cnt[id]++;
                    }
                }
            }
            else
            {
                int timestamp = stoi(event[1]);
                int id = stoi(event[2]);
                statsLast[id] = timestamp + 60;
            }
        }
        return cnt;
    }
};
