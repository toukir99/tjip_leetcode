class Solution {
public:
    void deleteNode(ListNode* node) {
        auto toRemove=node->next;
        node->val=node->next->val;
        node->next=node->next->next;
        delete(toRemove);
    }
};
