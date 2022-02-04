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
    void dfs(Node* cur, Node* par, vector<Node*> &visited)
    {
        visited[par->val] = par;
        for(auto i: cur->neighbors)
        {
            if(!visited[i->val])
            {
                Node* newnode = new Node(i->val);
                (par->neighbors).push_back(newnode);
                dfs(i,newnode,visited);
            }else
            {
                (par->neighbors).push_back(visited[i->val]);
            }
        }
    }
    
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return node;
        vector<Node *> visited(1005,NULL);
        Node* clone = new Node(node->val);
        visited[node->val] = clone;
        for(auto i: node->neighbors)
        {
            if(!visited[i->val])
            {
                Node* newnode = new Node(i->val);
                (clone->neighbors).push_back(newnode);
                dfs(i,newnode,visited);
            }else{
                (clone->neighbors).push_back(visited[i->val]);
            }
        }
        return clone;
    }
};
