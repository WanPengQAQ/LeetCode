/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //using O(n)time complexity and O(n)space complexity
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        
        while(head){
            v.push_back(head);
            head = head->next;
        }
        
        ListNode helper(0);
        helper.next = head;
        
        ListNode *p = &helper;
        
        for(int i = 0; i < v.size()/2; i++){
            p->next = v[i]; p = p->next;
            
            p->next = v[v.size() - 1 - i]; p = p->next;
        }
        
        if(v.size() % 2 == 1){
            p->next = v[v.size()/2];
            p = p->next;
        }//中间还有个一个
        p->next = NULL;
    }
};
