class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int Max =0;
        vector<int> temp(nums.size());
        for(int i =0;i<nums.size();i++){
            Max = max(Max,nums[i]);
            temp[i] = gcd(nums[i],Max);
        }
        sort(temp.begin(),temp.end());
        long long sum =0;
        int i=0;
        int j = temp.size()-1;
        while(i<j) // n/2 pairs
        {
            sum += gcd(temp[i],temp[j]);
            i++;
            j--;
        }
        return sum;
    }
};