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
	ListNode* reverseList(ListNode* head) {
		if (!head) return NULL;
		ListNode *last = head, *next = head->next;
		while (next) {
			ListNode* temp = next->next;

			next->next = last;
			
			last = next;
			next = temp;
		}

		head->next = NULL;

		return last;
	}
};

//another

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if(head == NULL || head->next == NULL) return head;7
		ListNode new_head(0);
		new_head.next = head;
		
		ListNode* pre = &new_head;
        ListNode* cur = head; 
		
		while(cur && cur -> next){
		    ListNode* temp = pre -> next;
            pre -> next = cur -> next;
            cur -> next = cur -> next -> next; 
            pre -> next -> next = temp;
		}
		
		
		
		return new_head.next;
	}
};
