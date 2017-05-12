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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        https://leetcode.com/submissions/detail/102700958/
        for(int i = 0; i < v.size()/2; i++)
            if(v[i] != v[v.size() - 1 - i])
                return false;
        return true;
        
    }
};
