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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = 0;
		ListNode *temp = head;
		while (temp) {
			length++;
			temp = temp->next;
		}

		if (k > length || k == 0)
			return head;

		ListNode helper(0);
		helper.next = head;
		ListNode *p = &helper;

		while (k <= length  )
		{
			ListNode *tempHead = p->next;
			ListNode *temp;
			ListNode *Old = tempHead;
			ListNode *New = Old->next;
			for (int i = 1; i < k; i++) {
				temp = New->next;
				New->next = Old;

				Old = New;
				New = temp;
			}

			tempHead->next = New;
			p->next = Old;

			p = tempHead;

			length -= k;
		}
		
		return helper.next;
    }
};
