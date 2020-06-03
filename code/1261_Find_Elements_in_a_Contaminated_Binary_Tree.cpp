/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
private:
    vector<int> valVector;
public:
    FindElements(TreeNode* root) {
        // level order traverse
        if (!root) return;
        root->val = 0;
        queue<TreeNode*> tnQueue;
        tnQueue.push(root);
        while (!tnQueue.empty()) {
            TreeNode* node = tnQueue.front(); tnQueue.pop();
            valVector.push_back(node->val);
            if (node->left) {
                node->left->val = 2 * node->val + 1;
                tnQueue.push(node->left);
            }
            if (node->right) {
                node->right->val = 2 * node->val + 2;
                tnQueue.push(node->right);        
            }
        }
    }
    
    bool find(int target) {
        for (int i=0; i<valVector.size(); i++) {
            if (target == valVector[i]) return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */