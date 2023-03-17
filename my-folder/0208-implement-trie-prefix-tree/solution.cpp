class TrieNode
{
    public:
    bool flag;
    TrieNode* links[26];
    TrieNode* in(char ch)
    {
        if(links[ch - 'a'] != NULL)
        {
            return links[ch - 'a'];
        }
        else
            links[ch - 'a'] = new TrieNode();
        return links[ch - 'a'];
    }
    void set()
    {
        flag = true;
    }
    TrieNode* nxt(char ch)
    {
        return links[ch - 'a'];
    }
};
class Trie {
public:
    TrieNode* t;
    Trie()
    {
        t = new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode* r = t;
        for(int i = 0 ; i < word.length() ; i++)
        {
            char ch = word[i];
            r = r->in(ch);
        }
        r->set();
    }
    
    bool search(string word)
    {
        TrieNode* r = t;
        for(int i = 0 ; i < word.length() ; i++)
        {
            char ch = word[i];
            r = r->nxt(ch);
            if(r == NULL)
                return false;
        }
        if(r->flag == true)
            return true;
        else
            return false;
    }
    
    bool startsWith(string prefix)
    {
        TrieNode* r = t;
        for(int i = 0 ; i < prefix.length() ; i++)
        {
            char ch = prefix[i];
            r = r->nxt(ch);
            if(r == NULL)
                return false;
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
