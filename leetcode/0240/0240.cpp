/*从左下角或者右上角开始搜索*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size(), n = matrix[0].size();
      int i = m - 1, j = 0;
      while(i >= 0 && j < n) {
        if(matrix[i][j] == target) {
            return true;
        }
        else if(matrix[i][j] < target) {
            ++j;
        }
        else if(matrix[i][j] > target) {
            --i;
        }
      } 
      return false;
    }
};

int main() {
  vector<vector<int>> mat = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
  int target = 5;
  cout << boolalpha << Solution().searchMatrix(mat, target) <<endl;
  system("PAUSE");
  return 0;
}
