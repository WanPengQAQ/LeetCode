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
