#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/// Dynamic Programming based on starting point
/// Time Complexity:  O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         if(intervals.size() == 0) {
            return 0;
        };

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

/*
        for (int i = 0; i <intervals.size(); i++) {
            cout << intervals[i][0] << ' ' << intervals[i][1] <<endl;
        }
*/

        int total = 0, prev = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < prev) {
                total++;
            } else {
                prev = intervals[i][1];
            }
        }
        return total;
    }
};


int main() {

    vector<vector<int>> interval1 = {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};
    cout << Solution().eraseOverlapIntervals(interval1) << endl;

    system( "PAUSE ");
    return 0;
}
