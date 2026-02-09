/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA ; 
        ListNode* tempB = headB ; 

        int n1 = 0 ;
        int n2 = 0 ;

        while(tempA){
            n1++;
            tempA = tempA -> next ;
        }


        while(tempB){
            n2++;
            tempB = tempB -> next ; 
        }

        tempA = headA;
        tempB = headB;

        if(n1> n2){
        for (int i = 0; i < n1 - n2; i++) {
                tempA = tempA->next;
            }
        }
        else{
             for (int i = 0; i < n2 - n1; i++) {
                tempB = tempB->next;
            }
        }

        while (tempA && tempB) {
            if (tempA == tempB) return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }

      
      return NULL ; 


    }
};