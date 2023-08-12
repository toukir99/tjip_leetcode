//tc: O(n)
//sc: O(n)

class Solution {
public:
    TreeNode* buildBST(int L, int R, vector<int>& nums){
        if(L>R) return nullptr;
        int M = L + (R-L)/2;
        TreeNode* root = new TreeNode(nums[M]);
        root->left = buildBST(L,M-1,nums);
        root->right = buildBST(M+1,R,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(0,nums.size()-1,nums);
    }
};
