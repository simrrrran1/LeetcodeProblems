class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int res = INT_MIN;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                counter++;
                if (counter == k) {
                    res = curr->val;
                }
                curr = curr->right;
            } else {
                TreeNode* pre = curr->left;
                while (pre->right != nullptr && pre->right != curr) {
                    pre = pre->right;
                }

                if (pre->right == nullptr) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = nullptr;
                    counter++;
                    if (counter == k) {
                        res = curr->val;
                    }
                    curr = curr->right;
                }
            }
        }

        return res;
    }
};
