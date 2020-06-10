class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if ((nums2.size() == 0) || (nums1.size() == 0)) return result;
        unordered_map<int, int> m;

        for (int i=0; i<nums2.size()-1; i++) {
            for (int j=i+1; j<nums2.size(); j++) {
                if (nums2[i]<nums2[j]) {
                    // cout << nums2[i] << " " << nums2[j] << endl;
                    m.insert(pair<int, int>(nums2[i], nums2[j]));
                    break;
                } 
            }
            m.insert(pair<int, int>(nums2[i], -1));
        }
        m.insert(pair<int, int>(nums2[nums2.size()-1], -1));

        for (int i=0; i<nums1.size(); i++) {
            // cout << nums1[i] << " " << m[nums1[i]] << endl;
            result.push_back(m[nums1[i]]);
        }
        return result;
    }
};