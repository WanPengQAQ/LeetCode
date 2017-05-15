/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // o(n)time and o(n)space
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> s1, s2;
        
        while(headA || headB){
            if(headA){  s1.push(headA);headA = headA->next; }
            if(headB){  s2.push(headB);headB = headB->next; }
        }
        
        ListNode *res = NULL;
        
        while( !s1.empty()  && !s2.empty() &&   s1.top() == s2.top()){
            res = s1.top();
            s1.pop();s2.pop();
        }
        
        return res;
    }
};
