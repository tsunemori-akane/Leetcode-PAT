/*定义一个数组 dp，dp[i] 表示抢劫到第 i 个房子时
**转移方程为 dp[i] = max( dp[i-1],nums[i-1] + dp[i-2] )
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
      if(nums.size() == 2) return nums[0] < nums[1] ? nums[1] : nums[0];
      if(nums.size() == 1) return nums[0];
      int max1 = 0, max2 = 0, imax;
      for (int i = 0; i < nums.size(); i++) {
        imax = max1 > ( max2 + nums[i] ) ? max1 : ( max2 + nums[i] );
        max2 = max1;
        max1 = imax;
      }
      return imax;
    }
};

int main() {

    int nums[] = {2, 1, 1, 2};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));

    cout << Solution().rob(vec) << endl;
    system( "PAUSE ");
    return 0;
}
