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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0), *p = res;
        
        int extra = 0;
        
        
        while(l1 || l2 || extra){
            int a = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = a/10;
            p->next = new ListNode( a % 10 );
            p = p->next;
            
            if(l1)  l1 = l1->next;
            if(l2)  l2 = l2->next;
        }
        
        return res->next;
    }
};
