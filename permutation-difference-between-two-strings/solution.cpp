class Solution {
public:
    int findPermutationDifference(string s, string t) {
        // unordered_map<int,int> m1;
        int sum =0;
        unordered_map<int,int> m2;
        for(int i=0;i<s.size();i++){
            // m1[s[i]] = i;
            m2[t[i]] = i;
        }
        for(int i=0;i<s.size();i++){
            sum += abs(i - m2[s[i]]); 
        }
        return sum;
    }
};