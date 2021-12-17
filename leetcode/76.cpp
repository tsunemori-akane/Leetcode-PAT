//草稿
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> win;
        unordered_map<char, int> re;
        for(auto e:t) re[e] ++; //{A:1, B:1, C:1}
        int cnt = 0, minLen;
        for(int i, j=0; j < s.length();j ++) {
            if(re.count([s[j])) {
                win[s[j]] ++;
                cnt += 1;
            }
            while(cnt == t.length()) {
                if(re.count(s[i])) {
                    win[s[i]] --;
                    if(win[s[i]] < re[s[i]]) cnt--;
                }
                i++;
            }
            minLen = j-i;
        }
    }
};
