class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;

        while (temp) {
            len++;
            temp = temp->next;
        }

        if (len == n) return head->next;

        temp = head;
        for (int i = 0; i < len - n - 1; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};
