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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;
            
        ListNode *walk = head, *run = head;
        bool isCycle = false;
        while(walk && run){
            walk = walk->next;
            if(run->next == NULL)
                return NULL;
            else
                run = run->next->next;
                
            if(walk == run){
                isCycle = true;
                break;
            }
        }
        
        if(isCycle){ 
            walk = head;
            while(walk != run){
                walk = walk->next;
                run = run->next;
            }
            return walk;
        }
        else
            return NULL;

    }
};
