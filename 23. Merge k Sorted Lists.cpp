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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        return divide(lists, 0, lists.size() - 1);
    }
    
    ListNode* divide(vector<ListNode*>& lists, int begin, int end){
        if(begin == end)    
            return lists[begin];
        else if(begin > end)
            return NULL;
            
        int min = (begin + end) / 2;    //0
        
        ListNode *l1 = divide(lists, begin ,min); //0 0
        ListNode *l2 = divide(lists, min + 1 ,end); //0 1
        
        return merge(l1, l2);
    }
    
    ListNode* merge(ListNode *l1, ListNode *l2){
        ListNode newNode(0);
        newNode.next = NULL;
        ListNode *p = &newNode;
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
        
        p->next = l1 ? l1 : l2;
        
        return newNode.next;
    }
};
