class Solution {
public:
    int ColumnCount(string s, int numRows) {
        int flag = 0;
        int check = 0;
        int cnt = 0;
        while (check < s.size()) {
            if (flag == 0) {
                check += numRows;
                cnt++;
                flag = 1;
            } else {
                check += numRows - 2;
                cnt += (numRows - 2);
                flag = 0;
            }
        }
        return cnt;
    }
    string convert(string s, int numRows) {
        int m = 0;       // column count
        int n = numRows; // row count
        if (n == 1)
            return s;
        if (n == 2)
            m = (s.size() + 1) / 2;
        else if (n > 2)
            m = ColumnCount(s, n);

        vector<vector<char>> matrix(n, vector<char>(m, '\0'));
        int flag = 0;
        int i = 0;
        int column = 0;
        while (i < s.size()) {
            if (flag == 0) {
                int check = 0;
                while (check < n && i < s.size()) {
                    matrix[check][column] = s[i];
                    i++;
                    check++;
                }
                flag = 1;
                column++;
            }
            if (flag == 1) {
                int row = n - 2;
                while (row != 0 && column < m && i < s.size()) {
                    matrix[row][column] = s[i];
                    column++;
                    row--;
                    i++;
                }
                flag = 0;
            }
        }
        string ans(s.size(), ' ');
        int row = 0;
        int j = 0;
        while (row < n) {
            int k = 0;
            while (k < m) {
                if (matrix[row][k] != '\0') {
                    ans[j] = matrix[row][k];
                    j++;
                }
                k++;
            }
            row++;
        }
        return ans;
    }
};