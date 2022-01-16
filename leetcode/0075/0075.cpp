/*这个问题类似快排中partition过程，只是需要用到三个指针：一个前指针begin，一个中指针current，一个后指针end，current指针遍历整个数组序列
**1-current指针所指元素为0时，与begin指针所指的元素交换~ 而后current++，begin++ 
**2-current指针所指元素为1时，不做任何交换（即球不动）~ 而后current++ 
**3-current指针所指元素为2时，与end指针所指的元素交换~ 而后，current指针不动，end-- 
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int l=0, r=nums.size()-1;
    for(int p=0;p<nums.size() && l<=r;) {
        if(nums[p] == 0 && p >= l) {
            swap(nums[p], nums[l]);
            l++;
        }else if(nums[p] == 2 && p <= r) {
            swap(nums[p], nums[r]);
            r--;
        }else
            p++;
    }
  }
};

void print_arr(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {
    vector<int> vec1 ={2,0,2,1,1,0};
    Solution().sortColors(vec1);
    print_arr(vec1);
    return 0;
}
