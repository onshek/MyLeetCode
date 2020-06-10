class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // related: 0078
        vector<int> current = {0};
        construct(0, graph.size()-1, current, graph);
        return result;
    }

    void construct(int idx, int target, vector<int> current, vector<vector<int>>& graph) {
        for (int item: graph[idx]) {
            current.push_back(item);
            if (item == target) result.push_back(current);
            construct(item, target, current, graph);
            current.pop_back();
        }
    }
};