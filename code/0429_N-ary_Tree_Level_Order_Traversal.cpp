/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<Node*> q; q.push(root);
        while (!q.empty()) {
            res.push_back(vector<int>());
            int _size = q.size();
            for (int i=0; i<_size; i++) {
                Node* tmp = q.front(); q.pop();
                res.back().push_back(tmp->val);
                for (int j=0; j<tmp->children.size(); j++) q.push(tmp->children[j]);
            }
        }
        return res;
    }
};