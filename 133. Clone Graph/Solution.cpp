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
    Node* helper(Node* node,unordered_map<Node*,Node*>&mp){
        Node* newNode=new Node(node->val);
        mp[node]=newNode;

        for(auto i:node->neighbors){
            if(mp.find(i)==mp.end()){
                (newNode->neighbors).push_back(helper(i,mp));
            }else{
                (newNode->neighbors).push_back(mp[i]);
            }
        }
        return newNode;

    }
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        unordered_map<Node*,Node*>mp;
        return helper(node,mp);
    }
};