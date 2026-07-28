class Solution {
public:
    bool search(int i, int j, int n, int m, int k, vector<vector<char>>& board,
                string& word) {
        if (k == word.size())
            return true;

        if (i < 0 || j < 0 || i == n || j == m || board[i][j] != word[k])
            return false;

        char store = board[i][j];
        board[i][j] = '#'; // repetetion avoid karne ke liye ek hi char ka

        bool p1 = search(i + 1, j, n, m, k + 1, board, word);
        bool p2 = search(i, j + 1, n, m, k + 1, board, word);
        bool p3 = search(i, j - 1, n, m, k + 1, board, word);
        bool p4 = search(i - 1, j, n, m, k + 1, board, word);

        board[i][j] = store; // uss ki original value ko restore karne ke liye

        return p1 || p2 || p3 || p4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();    // for row
        int m = board[0].size(); // for column

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (search(i, j, n, m, 0, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};