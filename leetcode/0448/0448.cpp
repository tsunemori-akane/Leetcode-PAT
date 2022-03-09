#include <iostream>
#include <vector>
using namespace std;

class Solution {
public: 
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    vector<int> arr(n, 0);
    vector<int> ans;
    for(auto &num : nums) {
      arr[num-1] -= 1;
    }
    for(int i = 0; i < arr.size(); i++) {
      if(arr[i] == 0) {
        ans.push_back(i+1);
      }
    }
    return ans;
  }
};

void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {
  vector<int> nums1 = {4, 3, 2, 7, 8, 2, 3, 1};
  printVec(solution().findDisappearedNumbers(nums1));
  system("PAUSE");
  return 0;
}
