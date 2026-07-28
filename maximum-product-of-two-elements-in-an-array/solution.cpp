class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a= 0;
        int b =0;
        for(int i=0;i<nums.size();i++){
            int oa = a;
            a = max(a,nums[i]);
            b = max(b,min(oa,nums[i]));
        }
        return (a-1)*(b-1);
    }
};