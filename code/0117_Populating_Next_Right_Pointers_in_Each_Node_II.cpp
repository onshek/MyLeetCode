/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> Q;
        if (!root) return root;
        Q.push(root);

        while (!Q.empty()) {
            int _size = Q.size();
            for (int i=0; i<_size; i++) {
                Node* node = Q.front();
                Q.pop();
                if (i < _size-1) {
                    node->next = Q.front();
                    //cout << node->val << "->" << node->next->val << endl;
                }
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
            }
        }
        return root;
    }
};