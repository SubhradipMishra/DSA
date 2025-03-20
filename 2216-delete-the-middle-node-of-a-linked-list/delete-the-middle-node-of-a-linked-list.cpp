class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;
        }
        
        ListNode* slow = head;  
        ListNode* fast = head; 
        int x = 0;

        while (fast && fast->next) {
            slow = slow->next; 
            fast = fast->next->next;
            x++;
        }

        ListNode* temp = head;

        for (int i = 1; i < x; i++) {
            temp = temp->next;
        }

        if (temp->next) {
            temp->next = temp->next->next;
        }

        return head;
    }
};