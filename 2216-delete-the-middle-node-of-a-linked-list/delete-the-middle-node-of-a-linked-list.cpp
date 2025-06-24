
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) { 
        if(head->next ==  NULL )  return head->next; 
         ListNode* slow = head ; 
         ListNode* fast = head ; 
         while(fast && fast->next){
            slow = slow->next ; 
            fast = fast->next->next ;
         }


         ListNode* temp = head ; 
         while ( temp->next && temp->next != slow  ){
            temp = temp->next ;
         }

         if(temp->next)temp->next = temp->next->next ; 

         return head ; 

    }
};