class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct Cmp { bool operator()(ListNode* a, ListNode* b) const { return a->val > b->val; } };
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
        for (auto p : lists) if (p) pq.push(p);
        ListNode dummy(0), *t = &dummy;
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            t->next = p; t = t->next;
            if (p->next) pq.push(p->next);
        }
        return dummy.next;
    }
};
