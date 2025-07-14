class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num = 0;
        ListNode* temp = head;
        
        while (temp) {
            num = num * 2 + temp->val; // Shift left and add current bit
            temp = temp->next;
        }
        
        return num;
    }
};
