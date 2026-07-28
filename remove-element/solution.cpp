class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n =nums.size();
        int k =0;
        int p1 =0;
        int p2 =n-1;
        while(p1<p2){
            if(nums[p1] != val) p1++;
            if(nums[p2] == val) p2--;
            if(p1<p2){
            if(nums[p1] == val && nums[p2] != val){
                swap(nums[p1],nums[p2]);
                p1++;
                p2--;
            }
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i] != val ) k++;
            else break;
        }
        return k ;
    }
};