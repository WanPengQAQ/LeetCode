/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode*>v;
        while(head){
            v.push_back(head);
            head = head->next;
        }
        
        return toBST(v, 0, v.size() - 1);
        
    }
    
    TreeNode* toBST(vector<ListNode*>&v, int begin, int end)
    {
        if(begin > end)
            return NULL;
        int min = (begin + end) / 2;
        
        TreeNode *newNode = new TreeNode(0);
        newNode->val = v[min]->val;
        newNode->left = toBST(v, begin, min - 1);
        newNode->right = toBST(v, min + 1, end);
        
        
        return newNode;
    }
    
};
