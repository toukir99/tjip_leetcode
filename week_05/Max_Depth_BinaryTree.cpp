//tc: O(n) n= maximum number of nodes
//sc: O(n) 

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};
