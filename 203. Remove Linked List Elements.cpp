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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode tempHead(0);
        tempHead.next = head;
        
        ListNode *p = &tempHead;
        
        while(p != NULL && p->next){
            ListNode *nextNode = p->next;
            
            if(nextNode->val == val){
                p->next = nextNode->next;
                delete nextNode;
            }
            else
                p = p->next;
            
            
        }
        
        return tempHead.next;
    }
};
