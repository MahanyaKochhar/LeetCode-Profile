class TrieNode
{
    public:
    TrieNode* links[26];
    bool flag;
    bool contains(char ch)
    {
    	if(links[ch-'a']!=NULL)
    		return true;
    	else
    		return false;
    }
    void set(char ch)
    {
     links[ch-'a']=new TrieNode();
    }
    TrieNode* getnext(char ch)
    {
    	return links[ch-'a'];
    }
    void setflag()
    {
    	flag=true;
    }
    bool check()
    {
    	return flag;
    }

};
class Trie {
public:
    TrieNode* root;
    Trie()
    {
        root=new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->contains(word[i]))
            {
            	node->set(word[i]);
            }
            node=node->getnext(word[i]);
                                   
                                  
        }
        node->setflag();
    }
    
    bool search(string word)
    {
        TrieNode* node=root;
        for(int i=0;i<word.length();i++)
        {
        	if(!node->contains(word[i]))
        		return false;
        	node=node->getnext(word[i]);
        }
        return node->check();
    }
    
    bool startsWith(string prefix)
    {
        string word=prefix;
        TrieNode* node=root;
         for(int i=0;i<word.length();i++)
        {
        	if(!node->contains(word[i]))
        		return false;
        	node=node->getnext(word[i]);
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
