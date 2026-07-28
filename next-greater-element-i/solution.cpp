class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> mpp;
        mpp[nums2[nums2.size() - 1]] = -1;
        st.push(nums2[nums2.size() - 1]);
        for (int i = nums2.size() - 2; i >= 0; i--) {
            while (!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }
            if (st.empty()) {
                st.push(nums2[i]);
                mpp[nums2[i]] = -1;
            } else {
                mpp[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
        }
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};