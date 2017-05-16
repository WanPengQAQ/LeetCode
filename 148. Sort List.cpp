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

    int Count(ListNode* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        int length = Count(head);
        
        ListNode *min = head;
        length = length/2 - 1;
        while(length--)
            min = min->next;
            
        ListNode *leftend = min;  
        min = min->next;
        leftend->next = NULL;
        
        ListNode *p1 = sortList(head);
        ListNode *p2 = sortList(min);
        
        return merge(p1, p2);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode tempHead(0);
        ListNode *p = &tempHead;
        tempHead.next = NULL;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                p->next = l1; 
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        
        while(l1){
            p->next = l1;
            p = p->next;
            l1 = l1->next;
        }
        
        while(l2){
            p->next = l2;
            p = p->next;
            l2 = l2->next;
        }
        
        return tempHead.next;
        
    }
};
