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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode helper(0);
        helper.next = head;
        
        ListNode *pre = &helper, *end = &helper;
        
        for(int i = 1; i <= n; i++)
            end = end->next;
            
        while(end->next){
            pre = pre->next;
            end = end->next;
        }
        
        ListNode *temp = pre->next;
        pre->next = pre->next->next;
        delete temp;
        return helper.next;
    }
};
