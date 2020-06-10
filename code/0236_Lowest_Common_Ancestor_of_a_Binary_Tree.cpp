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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        // level order traverse + map
        unordered_map<TreeNode*, TreeNode*> tnMap;
        queue<TreeNode*> tnQueue; tnQueue.push(root);  // record pair(child, parent)
        TreeNode* oldQ = q;
        int cnt = 0;  // stop while loop if p and q has been found
        while (!tnQueue.empty() && cnt<2) {
            TreeNode* node = tnQueue.front(); tnQueue.pop();
            if (node->val==p->val || node->val == q->val) cnt++;
            if (node->left) {
                tnQueue.push(node->left);
                tnMap.insert(pair<TreeNode*, TreeNode*>(node->left, node));
            }
            if (node->right) {
                tnQueue.push(node->right);
                tnMap.insert(pair<TreeNode*, TreeNode*>(node->right, node));
            }
        }


        while (p) {
            while (q) {
                // cout << "p=" << p->val << ", q=" << q->val << endl;
                if (p->val == q->val) return p;
                else q = tnMap[q];
            }
            p = tnMap[p]; q = oldQ;
        }
        return nullptr;
    }
};