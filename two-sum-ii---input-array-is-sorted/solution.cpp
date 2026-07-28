class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size() == 2) return {1,2};
        for(int i=0;i<numbers.size();i++){
             int low = i;
             int high = numbers.size()-1;
             while(low<=high){
            int mid = (low+high)/2;
            if(numbers[mid] + numbers[i] == target) {
                if(mid != i)return{i+1,mid+1};
                else return{i+1,i+2};
            }
            if(numbers[mid]+numbers[i]> target) high = mid -1;
            if(numbers[mid]+numbers[i]< target) low = mid +1;

        }
    }
       return {};
    }
};