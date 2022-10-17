class TrieNode
{
public:
	TrieNode* links[2];
	bool check(int val)
	{
		if(links[val]!=NULL)
			return true;
		else
			return false;

	}
	TrieNode* getnext(int val)
	{
		if(links[val]!=NULL)
			return links[val];
		else
			return links[1-val];
	}
	void setnode(int val)
	{
		links[val]=new TrieNode();
	}
	TrieNode* nextnode(int val)
	{
		return links[val];
	}

};
class Trie
{
public:
	TrieNode* root;
	Trie()
	{
		root=new TrieNode();
	}
	void insert(int nums)
	{
		TrieNode* node=root;
		for(int j=31;j>=0;j--)
		{
			if(nums&(1<<j))
			{
				if(!node->check(1))
				{
					node->setnode(1);
				}
				node=node->nextnode(1);
			}
			else
			{
				if(!node->check(0))
				{
					node->setnode(0);
				}
				node=node->nextnode(0);

					
			}
				}
		}
	int solve(int nums)
	{
	    int val=0;
		TrieNode* node=root;
		for(int j=31;j>=0;j--)
		{
			if(nums&(1<<j))
			{
				if(node->check(0))
					val+=pow(2,j);
				node=node->getnext(0);
			}
			else
			{
				if(node->check(1))
					val+=pow(2,j);
				node=node->getnext(1);
			}
		}
		return val;
	}

};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums)
    {
        Trie obj;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            
        	if(i!=0)
        	{
        		int val=obj.solve(nums[i]);
        		ans=max(ans,val);
        	}
        	obj.insert(nums[i]);
        }
        return ans;
    }
};
