class TrieNode
{
    public:
    vector<TrieNode*> links{26};
    bool flag;
};
class Trie {
TrieNode* root;
public:
    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode *curr = root;
        for(int i = 0 ; i < word.length(); i++)
        {
            int pos = word[i] - 'a';
            if(curr->links[pos] == NULL)
            {
                TrieNode * newNode = new TrieNode();
                curr->links[pos] = newNode;
            }
            curr = curr->links[pos];
        }
        curr->flag = true;
    }
    
    bool search(string word)
    {
        TrieNode *curr = root;
        for(int i = 0 ; i < word.length(); i++)
        {
            int pos = word[i] - 'a';
            if(curr->links[pos] != NULL)
            {
                curr = curr->links[pos];
            }
            else
            {
                return false;
            }
        }
        return curr->flag;
    }
    
    bool startsWith(string prefix)
    {
       TrieNode *curr = root;
        for(int i = 0 ; i < prefix.length(); i++)
        {
            int pos = prefix[i] - 'a';
            if(curr->links[pos] != NULL)
            {
                curr = curr->links[pos];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
