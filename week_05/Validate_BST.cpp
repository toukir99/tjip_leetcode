//tc: O(n)
//sc: O(h)

class Solution {
public:
    bool isBST(TreeNode* root, TreeNode* l, TreeNode* r){
        if(!root)
            return true;
        
        if((l && root->val <= l->val) || (r && root->val >= r->val))
            return false;

        return isBST(root->left, l, root) && isBST(root->right, root, r);
    }
    
    bool isValidBST(TreeNode* root) {
        return isBST(root, NULL, NULL);
    }
};
