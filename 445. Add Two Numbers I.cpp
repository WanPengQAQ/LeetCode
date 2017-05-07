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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<ListNode*> s1, s2;
		ListNode res(0);
		while (l1) { s1.push(l1); l1 = l1->next; }
		while (l2) { s2.push(l2); l2 = l2->next; }

		int carry = 0;
		while (!s1.empty() || !s2.empty() || carry) {
			int sum = carry;
			if (!s1.empty()) { sum += s1.top()->val; s1.pop(); }
			if (!s2.empty()) { sum += s2.top()->val; s2.pop(); }
			ListNode *p = new ListNode(sum % 10);
			p->next = res.next;
			res.next = p;
			carry = sum / 10;
		}
		return res.next;
	}
    
};
