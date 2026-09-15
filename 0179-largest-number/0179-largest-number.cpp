class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        arr.reserve(nums.size());
        for(int it: nums){
            arr.push_back(to_string(it));
        }
        sort(arr.begin(),arr.end(),[](const string& a, const string& b){
            return a+b > b+a;
        });

        if( arr[0] == "0") return "0";

        int totallen = 0;
        for(const string& s: arr) totallen += s.size();
        string ans;
        ans.reserve(totallen);
        for(const string& s : arr) ans+= s;

        return ans;
    }
};