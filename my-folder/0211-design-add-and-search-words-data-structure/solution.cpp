class TrieNode
{
    public:
    vector<TrieNode*> links{26};
    bool flag;
};

class WordDictionary {
TrieNode* root;
public:
    WordDictionary()
    {
        root = new TrieNode;
    }

    bool findWord(string word,int idx,TrieNode* curr)
    {
        if(idx == word.length())
        {
            return curr->flag;
        }
        int pos = word[idx] - 'a';
        if(pos >= 0 && pos <= 25)
        {
            if(curr->links[pos] != NULL)
            {
                return findWord(word,idx + 1,curr->links[pos]);
            }
            else
            {
                return false;
            }
        }
        else
        {
           int ans = false;
           for(int i = 0 ; i < 26; i++)
            {
                if(curr->links[i] != NULL)
                {
                    ans = ans | findWord(word,idx + 1,curr->links[i]);
                }
                if(ans)
                {
                    return ans;
                }
            }
            return ans;
        }
    }
    
    void addWord(string word)
    {
        TrieNode *curr = root;
        for(auto& ch : word)
        {
            int pos = ch - 'a';
            if(curr->links[pos] == NULL)
            {
                TrieNode* newNode = new TrieNode();
                curr->links[pos] = newNode;
            }
            curr = curr->links[pos];
        }
        curr->flag = true;
    }
    
    bool search(string word)
    {
        bool ans = findWord(word,0,root);
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
