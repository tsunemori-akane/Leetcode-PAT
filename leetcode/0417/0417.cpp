//对矩形四条边进行搜索。搜索完成后，只需遍历一遍矩阵，满足条件的位置即为两个大洋向上流都能到达的位置
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pathX[4] = {0, 0, 1, -1};
    int pathY[4] = {1, -1, 0, 0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; i ++) {
            dfs(matrix, pacific, i, 0);
            dfs(matrix, atlantic, i, n-1);
        }
        for (int i = 0; i < n; i ++) {
            dfs(matrix, pacific, 0, i);
            dfs(matrix, atlantic, m-1, i);
        }
        for (int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back(vector<int>{i, j});
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited,int x, int y) {
        if(visited[x][y]) return;
        visited[x][y] = true;
        int a, b;
        for (int index = 0; index != 4; index++) {
            a = x + pathX[index], b = y + pathY[index];
            if(a>=0 && a<matrix.size() && b>=0 && b<matrix[0].size() && matrix[a][b] >= matrix[x][y]) {
                dfs(matrix, visited, a, b);
            }
        }
    }
};
