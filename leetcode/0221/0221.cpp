/*动态规划解法
**状态转移方程dp(i,j) = min( dp(i,j−1),dp(i−1,j), dp(i−1,j−1) ) + 1
**用dp[i][j]来表示以(i, j)为右下角的方阵的边长
**如果当前的值为 1，那么要找出最长的边，就需要考虑从当前位置出发，上面，左边，左上的值都必须是 1，只有这样，再加上当前位置才有可能构成正方形
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int max_side;
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(matrix[i-1][j-1] == '1') {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
                max_side = max(max_side, dp[i][j]);
            }
        }
        return max_side*max_side;
    }
};

int main() {}
