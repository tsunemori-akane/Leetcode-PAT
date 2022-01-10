#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        int p = 0;
        for(p = 0; p+1 < nums.size(); p++) {
            if(nums[p] > nums[p+1]) {
                break;
            }
        }
        int l = 0, r = p;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                return true;
            }
            if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        l = p + 1, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                return true;
            }
            if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};

int main() {

    vector<int> nums1 = {4,5,6,7,0,1,2};
    cout << Solution().search(nums1, 0) << endl;

    vector<int> nums2 = {4,5,6,7,8,1,2,3};
    cout << Solution().search(nums2, 8) << endl;

    vector<int> nums3 = {1};
    cout << Solution().search(nums3, 0) << endl;
    system( "PAUSE ");
    return 0;
}
