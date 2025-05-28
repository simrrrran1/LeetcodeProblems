class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node with only one child or no child
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode* minNode = getMin(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }
        return root;
    }

    TreeNode* getMin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};
