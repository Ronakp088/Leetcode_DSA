class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = (low + high) / 2;

            // Ensure mid is even
            if (mid % 2 == 1) mid--;

            // If pair is intact, single is on the right
            if (nums[mid] == nums[mid + 1])
                low = mid + 2;
            else
                high = mid;
        }

        return nums[low];
    }
};