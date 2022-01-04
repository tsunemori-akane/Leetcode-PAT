#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        int l = left(nums, target);
        int r = right(nums, target)-1;
        if(nums.size() == l || nums[l] != target) return {-1, -1};
        return vector<int>{l, r};
    }


private:
    int left(vector<int>& nums, int target) {
        int ll = 0, lr = nums.size(), mid;
        while(ll < lr) {
            mid = ll + (lr-ll)/2;
            if(nums[mid] < target) {
                ll = mid + 1;
            }
            if(nums[mid] >= target) {
                lr = mid;
            }
        }
        return ll;
    }

    int right(vector<int>& nums, int target) {
        int rl = 0, rr = nums.size(), mid;
        while(rl < rr) {
            mid = rl + (rr-rl)/2;
            if(nums[mid] <= target) {
                rl = mid+1;
            }   
            if(nums[mid] > target) {
                rr = mid;
            }
        }
        return rr;
    }
};

void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    int nums[2] = {2,2};
    int target = 3;
    vector<int> vec(nums, nums + sizeof(nums) / sizeof(int));

    printVec(Solution().searchRange(vec, target));
    system( "PAUSE ");
    return 0;
}
