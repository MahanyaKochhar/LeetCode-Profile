const int mod=10001;
vector<vector<pair<int,int>>>m(mod);
vector<set<pair<int,int>>>m1(mod);
map<pair<int,int>,int>mp;
map<pair<int,int>,int>mp2;
set<pair<int,pair<int,int>>>s;
class MovieRentingSystem {
public:
    // vector<vector<pair<int,int>>> m(10001);
    // map<pair<int,int>,int> mp;
    // set<pair<int,pair<int,int>>> s;

    MovieRentingSystem(int n, vector<vector<int>>& entries)
    {
        mp.clear();
        mp2.clear();
        s.clear();
        m.assign(mod,{});
        m1.assign(mod,{});
        for(int i=0;i<entries.size();i++)
        {
            int shop=entries[i][0];
            int movie=entries[i][1];
            int price=entries[i][2];
            mp[{shop,movie}]=price;
            m[movie].push_back({price,shop});
            m1[movie].insert({price,shop});
            mp2[{shop,movie}]=m[movie].size()-1;
        }
    }
    
    vector<int> search(int movie)
    {
        vector<int>ans;
        // set<pair<int,int>>f;
        // for(int i=0;i<m[movie].size();i++)
        // {
        //     f.insert({m[movie][i].first,m[movie][i].second});
        // }
        for(auto x:m1[movie])
        {
            if(ans.size()==5)
                break;
            ans.push_back(x.second);
        }
        return ans;
    }
    
    void rent(int shop, int movie)
    {
        // for(int i=0;i<m[movie].size();i++)
        // {
        //     if(m[movie][i].second==shop)
        //     {
        int i=mp2[{shop,movie}];
        mp2[{m[movie][(int)m[movie].size()-1].second,movie}]=i;
        m[movie][i].second=m[movie][(int)m[movie].size()-1].second;
        int temp=m[movie][i].first;
        m[movie][i].first=m[movie][m[movie].size()-1].first;
        m[movie][m[movie].size()-1].second=shop;
        m[movie][m[movie].size()-1].first=temp;
        m1[movie].erase({mp[{shop,movie}],shop});
        s.insert({mp[{shop,movie}],{shop,movie}});
        m[movie].pop_back();
    }
    
    void drop(int shop, int movie)
    {
        m[movie].push_back({mp[{shop,movie}],shop});
        m1[movie].insert({mp[{shop,movie}],shop});
        mp2[{shop,movie}]=m[movie].size()-1;
        s.erase({mp[{shop,movie}],{shop,movie}});
    }
    
    vector<vector<int>> report()
    {
        vector<vector<int>>fin;
        for(auto x:s)
        {
            if(fin.size()==5)
                break;
            fin.push_back({x.second.first,x.second.second});
        }
        return fin;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
