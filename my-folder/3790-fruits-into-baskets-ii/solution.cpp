class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets)
    {
        int unplaced = fruits.size();
        vector<bool>vis(unplaced,false);
        for(int i = 0 ; i < fruits.size() ; i++)
        {
            for(int j = 0 ; j < baskets.size();j++)
            {
                if(baskets[j] >= fruits[i] && !vis[j])
                {
                    vis[j] = true;
                    unplaced--;
                    break;
                }
            }
        }
        return unplaced;
    }
};
