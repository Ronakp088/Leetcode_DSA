// har bar value pe hi BS lage ye esa nahi hita ,to agar ye na chalrah ho to arr ke index per BS lagao.
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() -1;
        while(low<=high){
            int mid = (low+high)/2;
            int missing = arr[mid] -(mid+1);
            if(missing < k) low = mid+1;
            else high = mid -1;
        }
    return k+high+1;
    // return low +k ; bhi chalega
    }
};