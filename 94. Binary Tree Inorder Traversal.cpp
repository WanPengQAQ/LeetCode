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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
            
        stack<TreeNode*> s;
        
        while(root){
            s.push(root);
            root = root->left;
        }
        
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            
            res.push_back(temp->val);
            
            if(temp->right){
                temp = temp->right;
                while(temp){
                    s.push(temp);
                    temp = temp->left;
                }
                
            }
        }
        
        
        return res;
    }
};
