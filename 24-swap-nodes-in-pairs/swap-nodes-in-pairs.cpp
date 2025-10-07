class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* b = head->next;
        head->next = swapPairs(b->next);
        b->next = head;
        return b;
    }
};
