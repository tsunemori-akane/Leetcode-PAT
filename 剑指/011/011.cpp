class Solution {
public:
    int minArray(vector<int>& v) {
        int min = 1;
        for(int i = v.size() - 1; i > 0; i--){
            if(v[i] < v[i-1]) {
                min = v[i];
                break;
            }
            if(i == 1) {
                min = v[0];
            }
        }
        return min;
    }
};
