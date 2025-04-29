/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(-1);
        ListNode* even = new ListNode(-1);  
        ListNode* tO   = odd ;
        ListNode* tE   = even ; 
        int i  =  1  ; 
        ListNode*  temp = head; 
        while(temp){
            if(i%2 != 0){
                tO->next = temp ; 
                tO = tO->next ;
                temp = temp->next ; 
            }
            else{
                tE->next = temp ; 
                tE = tE->next ;
                temp = temp->next ;
            }
            i++ ;
        }
        tO->next = even->next ; 
     tE->next = NULL  ; 

     return odd->next ;
    }
};