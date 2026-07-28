class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int max =0;
       int cut =0;
       for(int i=0; i<nums.size();i++){
        if(nums[i] == 1){
            cut++;
            if(cut > max) max =cut;
        }
        else{
            cut =0;
        }
       }
       return max;
    }
};