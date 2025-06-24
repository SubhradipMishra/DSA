class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0, n2 = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        // Find lengths of both lists
        while (tempA) {
            n1++;
            tempA = tempA->next;
        }

        while (tempB) {
            n2++;
            tempB = tempB->next;
        }

        tempA = headA;
        tempB = headB;

        // Align both lists
        if (n1 > n2) {
            for (int i = 0; i < n1 - n2; i++) {
                tempA = tempA->next;
            }
        } else {
            for (int i = 0; i < n2 - n1; i++) {
                tempB = tempB->next;
            }
        }

        // Traverse together to find intersection
        while (tempA && tempB) {
            if (tempA == tempB) return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return nullptr;  // No intersection
    }
};
