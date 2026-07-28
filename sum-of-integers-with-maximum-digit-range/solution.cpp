class Solution {
public:
    int sum(int n){
    int Min = INT_MAX;
    int Max = INT_MIN;
    int ans =0;
    while(n>=1){
        int q = n%10;
        Min = min(q,Min);
        Max = max(q,Max);
        n /= 10;
    }
    return Max-Min;
    }
    int maxDigitRange(vector<int>& nums) {
    int maxRange = INT_MIN;
    int ans = 0;
    for(int i=0;i<nums.size();i++){
        int temp = sum(nums[i]);
        if(temp > maxRange){
            maxRange = temp;
            ans = nums[i];       
        }
        else if(temp == maxRange){
            ans += nums[i];     
        }
    }
    return ans;
   }
};