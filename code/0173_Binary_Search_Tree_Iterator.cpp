/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    queue<int> q;
    stack<TreeNode*> s;

    BSTIterator(TreeNode* root) {
        while (true) {
            if (root) {
                s.push(root);
                root = root->left;
            } else if (!s.empty()) {
                root = s.top(); s.pop();
                q.push(root->val);
                root = root->right;
            } else {
                break;
            }
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int result = q.front(); q.pop();
        return result;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (q.size() > 0);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */