class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double result=0.0, area=0.0;
        for (int i=0; i<points.size()-2; i++) {
            for (int j=i+1; j<points.size()-1; j++) {
                for (int k=j+1; k<points.size(); k++) {
                    vector<int> a = points[i], b = points[j], c = points[k];
                    area = abs(a[0]*b[1] + b[0]*c[1] + c[0]*a[1]
                             - c[0]*b[1] - b[0]*a[1] - a[0]*c[1]) / 2.0;
                    cout << "i=" << i << ", j=" << j << ", k=" << k << ", area=" << area << endl; 
                    result = max(result, area);
                }
            }
        }
        return result;
    }
};

/*
执行用时：892 ms, 在所有 C++ 提交中击败了 5.00% 的用户
内存消耗：32.5 MB, 在所有 C++ 提交中击败了 5.55% 的用户
/*