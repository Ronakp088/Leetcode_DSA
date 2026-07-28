class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        k = k%nums.size();
        int d = nums.size() - k;
        int temp[d];
        for(int i=0;i<d;i++){
            temp[i] = nums[i];
        }
        for(int i =d;i<n;i++){
            nums[i-d] = nums[i];
        }
        for(int i = n-d;i<n;i++){
            nums[i] = temp[i -(n-d)];
        }
    }
};