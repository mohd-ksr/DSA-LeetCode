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
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        Node* root = new Node(node->val);
        unordered_map<Node*, Node*>mapp;
        mapp[node]=root;
        queue<pair<Node*, Node*>>q;
        q.push({node, root});
        while(!q.empty()){
            Node* node = q.front().first; 
            Node* root  = q.front().second;
            q.pop();
            for(auto nei:node->neighbors){
                // Node* newNode = new Node(nei->val);
                // root->neighbors.push_back(newNode);
                if(mapp.find(nei)!=mapp.end()){
                    root->neighbors.push_back(mapp[nei]);
                }
                else{
                    Node* newNode = new Node(nei->val);
                    root->neighbors.push_back(newNode);
                    mapp[nei]=newNode;
                    q.push({nei, newNode});
                }
            }
        }
        return root;
    }
};