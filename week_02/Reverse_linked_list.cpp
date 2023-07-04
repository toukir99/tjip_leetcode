class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        auto curr=head;
        ListNode* pre=nullptr;
        while(curr)
        {
            auto nxt= curr->next;
            curr->next=pre;
            pre=curr;
            curr=nxt;
        }
        return pre;
    }
};
