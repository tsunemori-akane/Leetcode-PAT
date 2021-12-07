#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) {
            return 0;
        };
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        int res = 1, prev = points[0][1];
        for (int i = 1; i < points.size(); i++ ) {
            if(points[i][0] <= prev) {
                if( points[i][1] <= prev ) {
                    prev = points[i][1];
                }
                continue;
            } else {
                prev = points[i][1];
                res ++;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> interval1 = {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
    cout << Solution().findMinArrowShots(interval1) << endl;

    system( "PAUSE ");
    return 0;
}
