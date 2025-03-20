
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head ;
        ListNode* fast = head ;
        bool flag = false ; 
        while(fast && fast->next){
            slow =slow->next ; 
            fast = fast->next->next ; 
            if(slow == fast){
               flag = true ; 
               break  ;
            }
        }

        if(flag){
             ListNode* temp = head ; 
                while(slow != temp){
                    slow =slow->next ; 
                    temp = temp->next ;
                   
                }

                return temp ;
        }
        return NULL ; 

    }
};