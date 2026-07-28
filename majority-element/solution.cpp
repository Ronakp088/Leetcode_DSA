class Solution {
public:
    int majorityElement(vector<int>& v) {
        int count =0;
        int el;
        for(int i =0; i<v.size(); i++){
            if(count == 0 ){
                count =1;
                el= v[i];
            }
            else if(v[i] == el) count++;
            else count-- ;
        }
        // int value =0;
        // for(int i =0; i<v.size();i++){
        //     if(v[i] == el) value++;
        // }
        // if(valuej)
        return el;
    }
};