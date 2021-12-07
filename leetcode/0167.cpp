#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0, e = numbers.size()-1, sum;
        while(target != numbers[s] + numbers[e]) {
            if(target < numbers[s] + numbers[e]) {
                e -= 1;
            }
            if(target > numbers[s] + numbers[e]) {
                s += 1;
            }
        }
        return vector<int>{s+1,e+1};
    }
};

void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    int nums[] = {2, 7, 11, 15};
    int target = 9;
    vector<int> vec(nums, nums + sizeof(nums) / sizeof(int));
    printVec(Solution().twoSum(vec, target));
    system( "PAUSE ");
    return 0;
}
