class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto left=head;
        auto right=head;
        while(n--)
        {
            right=right->next;
        }
        if(right==nullptr) return head->next;
        while(right->next)
        {
            right=right->next;
            left=left->next;
        }
        left->next=left->next->next;
        return head;
    }
};
