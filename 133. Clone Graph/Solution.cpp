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
    unordered_map<Node*, Node*> visited;

    Node* dfs(Node* node){
        if(visited[node]) return visited[node];

        Node* cloned_node = new Node(node->val);

        visited[node] = cloned_node;

        for(auto& i: node->neighbors){
            cloned_node->neighbors.push_back(dfs(i));
        }

        return cloned_node;

    }

    Node* cloneGraph(Node* node) {
        if(!node) return node;
        return dfs(node);
    }
};