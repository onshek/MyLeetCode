class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> record;
        for (int n: A) {
            if (record.count(n) == 0) {
                record.insert(make_pair(n, 1));
            } else {
                record[n] ++;
                if (record[n] == A.size() / 2) return n;
            }
        }
        return 0;
    }
};