/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<bool>visited;
    map<int,Node*>mp;
    Node* dfsclone(Node* node)
    {
        Node* newN=new Node();
        vector<Node*>ans;
        newN->val=node->val;
        visited[node->val]=true;
        mp[node->val]=newN;
        vector<Node*>n=node->neighbors;
        for(int i=0;i<n.size();i++)
        {
            Node* neigh=n[i];
            if(visited[neigh->val])
            {
                ans.push_back(mp[neigh->val]);
            }
            else
            {
                Node* curr=dfsclone(neigh);
                ans.push_back(curr);

            }

        }
        newN->neighbors=ans;
        return newN;
    }
    Node* cloneGraph(Node* node)
    {
        if(node==NULL)
            return NULL;
        visited.resize(101);
        Node* fin=dfsclone(node);
        return fin;
    }
};
