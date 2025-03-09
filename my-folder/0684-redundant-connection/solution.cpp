class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        vector<int>parent(edges.size() + 1);
        vector<int>size(edges.size() + 1,1);

           auto create_set = [&] (int v) -> void
           {
                parent[v] = v;
           };

           auto find_set = [&](auto self,int v) -> int
           {
                if(v == parent[v])
                {
                return v;
                }
                return parent[v] = self(self,parent[v]);
           };

           auto union_sets = [&](int a,int b)-> bool
           {
                int a1 = find_set(find_set,a);
                int b1 = find_set(find_set,b);
                if(a1 != b1)
                {
                    if(size[a1] < size[b1])
                        swap(a1,b1);
                    size[a1] += size[b1];
                    parent[b1] = a1;
                    return true;
                }
                else
                {
                    return false;
                }
           };

            for(int i = 1; i <= edges.size();i++)
            {
                create_set(i);
            }

            for(int i = 0 ; i < edges.size();i++)
            {
                bool ans = union_sets(edges[i][0],edges[i][1]);
                if(!ans)
                {
                    return {edges[i][0],edges[i][1]};
                }
            }
            return {};
    }
};
