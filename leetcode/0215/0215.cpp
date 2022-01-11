#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0,r = nums.size()-1;
        while(l < r) {
            int mid = Quickselect(nums, l, r);
            if(mid + 1 == k) {
                return nums[mid];
            }
            if(mid + 1 < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return nums[l];
    }

    int Quickselect(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        while(l < r) {
            while(nums[l] >= pivot && l < r) {
                l++;
            }
            nums[r] = nums[l];
            while(nums[r] <= pivot && l < r) {
                r--;
            }
            nums[l] = nums[r];
        }
        nums[r] = pivot;
        return r;
    }
};

void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    cout << Solution().findKthLargest(nums1, 2) << endl;
    // 5

    vector<int> nums2 = {3, 1, 2, 4};
    cout << Solution().findKthLargest(nums2, 2) << endl;
    // 3

    vector<int> nums3 = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    cout << Solution().findKthLargest(nums3, 8) << endl;
    // 3
    system("PAUSE");
    return 0;
}
