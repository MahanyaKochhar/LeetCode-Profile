class Solution {
public:
    int openLock(vector<string>& deadends, string target)
    {
        auto bfs = [&] () -> int {
            string start = "0000";
            
            queue<pair<string,int>>q;
            q.push({start,0});
            set<string>s;
            for(auto x: deadends)
            {
                s.insert(x);
            }
            if(s.find(start) != s.end())
            {
                return -1;
            }
            set<string>vis;
            
            while(!q.empty())
            {
                pair<string,int> el = q.front();
                q.pop();
                string curr = el.first;
                int cnt = el.second;
                if(curr == target)
                {
                    return cnt;
                }
                
                for(int j = 0 ; j < 4 ; j++)
                {
                    string tmp = curr;
                    char ch = curr[j];
                    int v = ch - '0';
                    v = (v + 1) % 10 ;
                    char newCh =(char)(v + '0');
                    tmp[j] = newCh;
                    if(s.find(tmp) == s.end() && vis.find(tmp) == vis.end())
                    {
                        q.push({tmp,cnt + 1});
                        vis.insert(tmp);
                    }

                    int v2 = ch - '0';
                    v2 = (v2 - 1 + 10) % 10;
                    char newCh2 =(char)(v2 + '0');
                    tmp[j] = newCh2;
                    if(s.find(tmp) == s.end() && vis.find(tmp) == vis.end())
                    {
                        q.push({tmp,cnt + 1});
                        vis.insert(tmp);
                    }
                }   
            }
            return -1;
        };

        return bfs();
    }
};
