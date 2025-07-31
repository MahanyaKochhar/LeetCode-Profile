class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr)
    {
        set<int>result;
        set<int>existing;
        for(int i = 0 ; i < arr.size(); i++)
        {
            set<int>current;
            current.insert(arr[i]);
            for(auto& x : existing)
            {
                current.insert(x | arr[i]);
            }
            for(auto& x : current)
            {
                result.insert(x);
            }
            existing = current;
        }
        return result.size();
    }
};
