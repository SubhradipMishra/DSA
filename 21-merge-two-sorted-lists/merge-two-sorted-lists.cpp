
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tempA = list1 ;
        ListNode* tempB = list2 ; 
        ListNode* ans = new ListNode(-1000);
        ListNode* temp = ans; 

        while(tempA && tempB){
          if(tempA->val <= tempB->val){
            temp->next = tempA ;
           
            tempA = tempA->next ;
            
          }
          else{
             temp->next = tempB ; 
          
             tempB = tempB->next ;
          }
          temp = temp->next ; 
        }

        if(!tempA) temp->next = tempB; 
        if(!tempB) temp->next = tempA ; 

        return ans->next ; 


    }
};