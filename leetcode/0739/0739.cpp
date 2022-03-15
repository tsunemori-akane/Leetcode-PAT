#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      stack<int> s;
      vector<int> res(temperatures.size(), 0);
      for(int i = 0 ; i < temperatures.size() ; i++) {
        while(!s.empty()) {
          if( temperatures[i] > temperatures[s.top()] ) {
            res[s.top()] = i - s.top();
            s.pop();
          } else {
            break;
          }
        }
        s.push(i);
      }
      return res;
    }
};

void printf(const vector<int>& vec) {
  for(int e: vec)
        cout << e << " ";
    cout << endl;
}
int main() {
  vector<int> nums1 = {5,3,4,7};
  printf(Solution().dailyTemperatures(nums1));
  system( "PAUSE ");
  return 0;
}
