
class Solution {
public:

    ListNode* mergeList(ListNode* a ,  ListNode* b){
        ListNode* ans = new ListNode(-10000) ; 
        ListNode* temp = ans ; 
        ListNode* tempA =  a ; 
        ListNode* tempB =  b ;

        while(tempA && tempB){
            if(tempA->val <= tempB->val){
                temp->next = tempA ; 
                temp = tempA ;
                tempA  = tempA->next ; 
            }
            else{
                temp->next = tempB; 
                temp = tempB ;
                tempB  = tempB->next ;
            }
           
        }

        if(!tempA){
            temp->next = tempB ; 
        }
        if(!tempB){
            temp->next = tempA ; 
        }



        return ans->next ; 

    }
    ListNode* sortList(ListNode* head) {
            if(!head  || !head->next)  return head ;  
            ListNode* slow = head ; 
            ListNode* fast = head  ;

            while(fast->next && fast->next->next){
                slow = slow->next ; 
                fast = fast->next->next ; 

            }

            ListNode* a = head ; 
            ListNode* b   = slow->next ; 
            slow-> next = NULL ; 
             a = sortList(a) ;
             b = sortList(b) ;

             ListNode* c = mergeList(a,b);


             return c ; 


    }
};