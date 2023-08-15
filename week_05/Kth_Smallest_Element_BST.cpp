//tc: O(k)
//sc: O(n)

class Solution {
private:
    class BSTIterator{
        private:
        TreeNode* root;
        stack<TreeNode*> nodesStack;
        public:
         BSTIterator(TreeNode* _root){ 
             root= _root;
             TreeNode* curr= root;
             while(curr){
                 nodesStack.push(curr);
                 curr = curr->left; 
             }
         }
         int getNext(){
             TreeNode* topNode = nodesStack.top();
             nodesStack.pop();
             if(topNode->right){
                 TreeNode* curr= topNode->right;
                 while(curr){
                 nodesStack.push(curr);
                 curr= curr->left;
                }
             }
            return topNode->val; 
         }
    };
public:
    int kthSmallest(TreeNode* root, int k) {
        BSTIterator bst(root);
        int result;
        for(int i=0;i<k;i++){
            result= bst.getNext();
        }
        return result;
    }
};
