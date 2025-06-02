
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp =  new ListNode(-1) ;
        ListNode* c  = temp ;
        while(list1 && list2 ){
            if(list1->val <  list2->val){
                c->next = list1 ;
                c = c->next;  
                list1 = list1->next ; 
                

            }

            else{
                  c->next = list2 ;
                c = c->next;  
                list2 = list2->next ; 
            }
        }

        if(!list1 ) c->next = list2 ;
        else c->next = list1 ; 

        return temp->next ; 
    }
};