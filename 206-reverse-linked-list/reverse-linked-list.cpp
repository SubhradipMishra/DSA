
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL ;
        ListNode* prev ;
        ListNode* temp = head ; 
        while(temp){
            ListNode* nxt = temp->next ;
            temp->next = prev ; 
            prev = temp;
            temp = nxt ; 
        }

        return  prev ; 
    }
};