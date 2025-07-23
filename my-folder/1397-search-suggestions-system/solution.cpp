class TrieNode
{
    public:
    vector<TrieNode*>links{26};
    bool flag;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
    {
        TrieNode* root = new TrieNode();
        map<TrieNode*,set<string>> mp;
        auto addWord = [&](string word) -> void {
            TrieNode* curr = root;
            for(int i = 0 ; i < word.length(); i++)
            {
                int pos = word[i] - 'a';
                if(curr->links[pos] == NULL)
                {
                    TrieNode* newNode = new TrieNode();
                    curr->links[pos] = newNode;
                }
                curr = curr->links[pos];
                mp[curr].insert(word);
            }
            curr->flag = true;
        };

        for(int i = 0 ; i < products.size(); i++)
        {
            string s = products[i];
            addWord(s);
        }

        TrieNode* curr = root;
        vector<vector<string>>fin(searchWord.length());
        for(int i = 0 ; i < searchWord.length(); i++)
        {
            int pos = searchWord[i] - 'a';
            if(curr->links[pos] != NULL)
            {
                curr = curr->links[pos];
                for(auto& x : mp[curr])
                {
                    fin[i].push_back(x);
                    if(fin[i].size() == 3)
                    {
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
        return fin;
    }
};
