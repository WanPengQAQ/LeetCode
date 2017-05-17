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
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode tempHead(0);
		tempHead.next = head;

		head = head->next;

		tempHead.next->next = NULL;

		//Insertion sort
		int length = 1;
		while (head) {

			ListNode *temp = &tempHead, *p = head;
			head = head->next;

			int tempLength = 0;
			while (tempLength++ < length && p->val >= temp->next->val)
				temp = temp->next;
            length++;
			p->next = temp->next;
			temp->next = p;
			
		}

		return tempHead.next;
	}
};
