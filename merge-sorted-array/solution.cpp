class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1= 0; // pointer for nums1; 
        int p2= 0; // pointer for nums2;
        while(p1<m && p2<n){
            if(nums1[p1] <= nums2[p2]) p1++;
            else{
                swap(nums1[p1],nums2[p2]);
                sort(nums2.begin(),nums2.end());
                p1++;
            }
        }
        sort(nums2.begin(),nums2.end());
        for(int i=m;i<m+n;i++){
            nums1[i] = nums2[i-m];
        }
    }
};