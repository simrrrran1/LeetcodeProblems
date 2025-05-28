/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void dfs(TreeNode* root, vector<string>& v){
        if(!root){
            v.push_back("N");
            return;
        }
        v.push_back(to_string(root->val));
        dfs(root->left, v);
        dfs(root->right, v);
    }
    string serialize(TreeNode* root) {
        string ans = "";
        vector<string> v;
        dfs(root, v);
        for(int i=0; i<v.size()-1; i++){
            ans += v[i];
            ans += ",";
        }
        ans += v[v.size()-1];
        cout<< ans << endl;
        return ans;
    }

    TreeNode* dfs1(vector<string>& v, int& i){
        if(v[i] == "N"){
            i += 1;
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(v[i]));
        i += 1;
        root->left = dfs1(v, i);
        root->right = dfs1(v, i);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            v.push_back(token);
        }
        int i = 0;
        return dfs1(v, i);
        //return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));