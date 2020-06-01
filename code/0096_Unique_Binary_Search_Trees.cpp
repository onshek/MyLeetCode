class Solution {
public:
    int numTrees(int n) {
        /*
        G(i) = sum(([F(i, n) for i in range(1, n+1)]);
        F(i, n) = G(i-1) * G(n-1);
        --> 
        G(i) = sum([G(i-1) * G(n-i) for i in range(1, n+1)]);
        */
        vector<int> res;
        res.push_back(1); res.push_back(1);
        for (int i=2; i<=n; i++) {
            int tmp = 0;
            for (int j=1; j<=i; j++) tmp += res[j-1] * res[i-j];
            res.push_back(tmp);
        }
        return res[res.size()-1];
    }
};