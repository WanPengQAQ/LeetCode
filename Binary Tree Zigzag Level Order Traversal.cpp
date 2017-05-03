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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL)
			return res;

		vector<int> a;

		TreeNode *last = root;
		TreeNode *next = NULL;
		int level = 0;
		queue<TreeNode*> q;

		q.push(root);

		while (!q.empty()) {

			TreeNode* v = q.front();
			q.pop();

			if (res.size() < level + 1) {
				
				res.push_back(a);
			}

			res[level].push_back(v->val);

			if (v->left) {
				q.push(v->left);
				next = v->left;
			}
			if (v->right) {
				q.push(v->right);
				next = v->right;
			}

			if (v == last) {
				last = next;
				level++;
			}

		}

		for (int i = 0; i < res.size(); i++) {
			// 1 3 5 7 9 need revser    
			if (i % 2 != 0)
				reverse(begin(res[i]), end(res[i]));
		}

		return res;
	}
};
