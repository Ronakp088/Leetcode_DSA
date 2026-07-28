class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        string temp = s;
        int p1 = 0;
       for(int i =0;i<n;i++){
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.begin()+(n-i-1));
        reverse(s.begin()+(n-i-1),s.end());
       if( s == goal) return true;
       else s = temp;
       }
        
        return false;
    }
};