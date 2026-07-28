class Solution {
public:
    bool check(vector<int>& nums) {
        // Step 1: Find the rotation point (where drop occurs)
        int x = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i+1]) {
                x = i + 1;
                break;
            }
        }

        // Step 2: Build rotated array B starting from x
        int n = nums.size();
        vector<int> B(n);
        for(int i = 0; i < n; i++) {
            B[i] = nums[(i + x) % n];
        }

        // Step 3: Check if B is non-decreasing
        for(int i = 0; i < n - 1; i++) {
            if(B[i+1] < B[i]) {
                return false;
            }
        }

        return true;
    }
};