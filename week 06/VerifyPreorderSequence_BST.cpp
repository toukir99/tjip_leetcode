//tc: O(n)
//sc: O(n)

class Solution {
public:
    void isValid(vector<int>& preorder,int& pos, int l, int h) {
        if(pos == preorder.size()) return;
        int val = preorder[pos];
        if(val < l || val > h) return;

        pos++;
        isValid(preorder, pos, l, val);
        isValid(preorder, pos, val, h);
    }
    bool verifyPreorder(vector<int>& preorder) {
        int pos = 0;
        isValid(preorder, pos, INT_MIN, INT_MAX);

        return pos == preorder.size() ? true : false;
    }
};
