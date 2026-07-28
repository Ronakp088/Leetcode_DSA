class Solution {
public:
    int RowSearch(vector<vector<int>>& matrix, int n, int m, int target) {
        for (int i = 0; i < n; i++) {
            int low = 0;
            int high = m - 1;
            if (target > matrix[i][m - 1])
                continue;
            else {
                while (low <= high) {
                    int mid = (high + low) >> 1;
                    if (matrix[i][mid] == target)
                        return 1;
                    else if (matrix[i][mid] > target)
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
            }
        }
        return 0;
    }
    int ColumnSearch(vector<vector<int>>& matrix, int n, int m, int target) {
        for (int i = 0; i < m; i++) {
            int low = 0;
            int high = n - 1;
            if (target > matrix[n - 1][i])
                continue;
            else {
                while (low <= high) {
                    int mid = (low + high) >> 1;
                    if (matrix[mid][i] == target)
                        return 1;
                    else if (matrix[mid][i] > target)
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
            }
        }
        return 0;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (n <= m) {
            if (RowSearch(matrix, n, m, target) == 1)
                return true;
        } else {
            if (ColumnSearch(matrix, n, m, target) == 1)
                return true;
        }

        return false;
    }
};