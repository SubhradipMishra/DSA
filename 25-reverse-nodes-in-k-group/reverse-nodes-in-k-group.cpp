class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 2) return head;

        ListNode* check = head;
        int count = 0;

        while (check) {
            count++;
            check = check->next;
        }

        int groups = count / k;

        ListNode* res = new ListNode(-1);
        ListNode* dummy = res;

        for (int i = 0; i < groups; i++) {
            ListNode* curr = nullptr;
            ListNode* groupHead = head;

            for (int j = 0; j < k; j++) {
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
            }

            dummy->next = curr;

            while (dummy->next)
                dummy = dummy->next;
        }

        dummy->next = head;

        return res->next;
    }
};