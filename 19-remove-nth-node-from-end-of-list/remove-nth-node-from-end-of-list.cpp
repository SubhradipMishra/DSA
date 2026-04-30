class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        if (len == n) {
            return head->next;
        }

        temp = head;
        int count = 1;
        while (count < len - n) {
            temp = temp->next;
            count++;
        }

        if (temp->next != nullptr) {
            temp->next = temp->next->next;
        }

        return head;
    }
};
