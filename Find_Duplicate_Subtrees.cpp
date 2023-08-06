//tc: O(n)
//sc: O(n)

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> dup_trees;
        calculateHash(root, dup_trees);
        return dup_trees;
    }
private:
    unordered_map<string,int> hashes;
    string calculateHash(TreeNode* root, vector<TreeNode*>&dup_trees){
        if(root==NULL) return "#";
        string leftHash= calculateHash(root->left, dup_trees);
        string rightHash= calculateHash(root->right, dup_trees);
        string currHash= to_string(root->val) + "," + leftHash + "," + rightHash;
        if(hashes.count(currHash) && hashes[currHash]==1){
            dup_trees.push_back(root);
        }
        hashes[currHash]++;
        return currHash;
    }
};
