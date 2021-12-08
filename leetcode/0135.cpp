#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> ac(ratings.size(), 1);
        int index1 = 1;
        int index2 = ratings.size()-2;
        while(index1 < ratings.size()) {
            if(ratings[index1] > ratings[index1-1]) {
                ac[index1] = ac[index1-1] + 1;
            } 
            index1 ++;
        };
        while(index2 >= 0) {
            if(ratings[index2] > ratings[index2+1] && ac[index2] <= ac[index2+1]) {
                ac[index2] = ac[index2+1] + 1;
            } 
            index2 --;
        };
        int res = accumulate(ac.begin(), ac.end(), 0);
        return res;
    }
};
