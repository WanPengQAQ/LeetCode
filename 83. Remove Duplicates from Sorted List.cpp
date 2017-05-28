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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;

        ListNode *p = head;
        
        while(p->next){
            if(p->val == p->next->val){
                ListNode *temp = p->next;
                p->next = temp->next;
                delete temp;
            }
            else
                p = p->next;
        }
        
        return head;
        
    }
};
