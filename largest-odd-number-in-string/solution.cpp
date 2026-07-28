class Solution {
public:
    string largestOddNumber(string num) {
        //int n = nums.size();
        int p1 = num.size()-1;
        int check =0;
        string ans = "";
        for(int i=num.size()-1;i>=0;i--){
            if(num[i]%2 == 1){
                check = 1;
                p1= i;
                break;
            }
        }
        if(check == 0) return "";
        else{
            for(int i =0;i<=p1;i++){
                ans += num[i];
            }
        }
       
        return ans;
    }
};