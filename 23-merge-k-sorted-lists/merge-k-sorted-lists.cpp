class Solution{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap
        }
    };

    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

    for (auto list : lists) {
        if (list) pq.push(list);
    }

    ListNode* dummy = new ListNode(-1000);
    ListNode* tail = dummy;

    while (!pq.empty()) {
        ListNode* smallest = pq.top(); pq.pop();
        tail->next = smallest;
        tail = tail->next;

        if (smallest->next) {
            pq.push(smallest->next);
        }
    }

    return dummy->next;
}

} ;