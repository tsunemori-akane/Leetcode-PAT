#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      int count = 0;
      vector<bool> visited(isConnected.size(), false);
      for(int i = 0; i < isConnected.size(); i++) {
        if(!visited[i]) {
          dfs(isConnected, visited, i);
          count++;
        }
      }
      return count;
    }

    void dfs(vector<vector<int>>& isConnected,  vector<bool>& visited, int i) {
      visited[i] = true;
      for(int k = 0; k < isConnected.size(); k++){
        if(isConnected[i][k] == 1 && !visited[k]) {
          dfs(isConnected, visited, k);
        }
      }
    };
};
