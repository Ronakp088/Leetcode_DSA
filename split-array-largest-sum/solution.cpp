// when ever the question is around  maximum of minimum or minimum of maximum think of "LS"

class Solution {
public:
    int countstudent(vector<int>& nums , int mid){
        int students =1; 
        int sum =0;
        for(int i =0;i<nums.size();i++){
        if(sum + nums[i] <= mid) sum += nums[i];
        else {
            students++;
            sum = nums[i];
        }
        }
        return students;
        
    } 
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) return -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low <= high){
            int mid = low + (high-low)/2;
            if(countstudent(nums,mid) > k) low = mid+1;
            else high = mid-1;
        } 
        return low;
    }
};