/*
**每次只考虑四个间隔 90 度的位置, 可以进行 O(1) 额外空间的旋转.
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp = 0, n = matrix.size()-1;
        for (int i = 0; i <= n / 2; ++i) {
            for (int j = i; j < n - i; ++j) {
                temp = matrix[j][n-i];
                matrix[j][n-i] = matrix[i][j];
                matrix[i][j] = matrix[n-j][i];
                matrix[n-j][i] = matrix[n-i][n-j];
                matrix[n-i][n-j] = temp;
            }
        }
    }
};
