class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        vector<int> prevMin(n);
        prevMin[0] = nums[0];
        for (int i = 1; i < n; i++) prevMin[i] = min(prevMin[i-1], nums[i]);

        stack<int> st; // candidates for nums[k]
        for (int j = n - 1; j >= 1; j--) {
            if (nums[j] > prevMin[j-1]) {
                while (!st.empty() && st.top() <= prevMin[j-1]) st.pop();
                if (!st.empty() && st.top() < nums[j]) return true;
                st.push(nums[j]);
            }
        }
        return false;
    }
};