class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n= nums.size();
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int i = 2;
        while(i<n){  if(arr1[arr1.size()-1]>arr2[arr2.size()-1]){
                arr1.push_back(nums[i]);
            }
            else arr2.push_back(nums[i]);
            
            i++;
        }
        for (int j= 0;j<arr2.size();j++){
            arr1.push_back(arr2[j]);
        }
        
        return arr1;
    }
};