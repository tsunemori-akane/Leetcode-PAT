class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> v(nums.size());
        int l = 0;
        int r = nums.size() - 1;

        for(auto e : nums) {
            if((e & 0x1) == 1) {
                v[l] = e;
                l++;
            } else {
                v[r] = e;
                r--;
            }
        }
        return v;
    }
};
