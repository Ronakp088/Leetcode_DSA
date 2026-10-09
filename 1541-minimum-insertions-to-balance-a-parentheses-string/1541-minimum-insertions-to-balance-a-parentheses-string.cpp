class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int open =0;
        int close = 0;
        int cnt =0;
        int j =0;
        while(s[j] == ')'){
            j++;
        }
        if(j%2 == 0) cnt += j/2;
        else cnt += (j+1)/2 + 1 ;
        for(int i =j;i<n;i++){
            if(s[i] == '('){
                if(close == 1){
                    cnt++;
                    close = 0;
                    open--;
                    if(open < 0){
                        cnt++;
                        open++;
                    }
                }
                open++;
            }
            else close++;
            if(close >= 2){
                close-=2;
                open--;
                if(open < 0){
                    cnt++;
                    open++;
                }
            }
        }
        if(2*open > close) cnt += 2*open-close;
        else{
            if( close > 0 && open == 0){
                if(close%2 == 0) cnt += close/2;
                else cnt += (close+1)/2 + 1 ;
            }
        }

        return cnt ;
    }
};