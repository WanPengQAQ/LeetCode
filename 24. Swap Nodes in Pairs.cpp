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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode helper(0);
        helper.next = NULL;
        
        ListNode *p = &helper, *now = head;
        
        ListNode *tempLast = NULL;
        while(now){
            ListNode *l1 = now, *l2 = now->next;
            // 1 2  3            
            if(l2 == NULL){
                now = NULL;
                p->next = l1; p = p->next;
            }
            else{
                now = l2->next;
                p->next = l2; p = p->next;
                p->next = l1; p = p->next;
            }
            
        }
        
        
        
        p->next = NULL;
        
        return helper.next;
    }
};
