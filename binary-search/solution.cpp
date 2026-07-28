class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n =nums.size();
        int low = 0;
        int high = n-1;
        int mid = (int)(low + (high-low)/2);
        while(low <= high ){
          int mid = (int)((low + high)/2);
        if( nums[low] == target) return low;
        else if(nums[high] == target) return high;
        else if(nums[mid] == target) return mid;
        else if (nums[mid]> target) high = mid -1;
        else low = mid+1;
        }
    return -1;
    }
};