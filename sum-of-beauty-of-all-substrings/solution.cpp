class Solution {
public:
// int beautyCalculator(string s,int i,int j){
//     unordered_map<int,int> Map;
//     for(int k=i;k<=j;k++){
//         Map[s[k]]++;
//     }
//     int MinNo =INT_MAX;
//     int MaxNo =INT_MIN;
//     for(auto& it : Map){
//         MinNo = min(it.second,MinNo);
//         MaxNo = max(it.second,MaxNo);
//     }
//     if((MaxNo-MinNo) > 0) return MaxNo-MinNo;
//     return 0;
// }
    int beautySum(string s) {
        int sum =0;
        // int MinNo =INT_MAX;
        // int MaxNo =INT_MIN;
        for(int i=0;i<s.size();i++){
         unordered_map<int,int> Map;
            for(int j =i;j<s.size();j++){
                Map[s[j]]++;
                  int MinNo =INT_MAX;
                  int MaxNo =INT_MIN;
                for(auto& it : Map){
                MinNo = min(it.second,MinNo);
                MaxNo = max(it.second,MaxNo);
              }
              sum += (MaxNo - MinNo);
            }
        }
        return sum;
    }
};