#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> win;
        unordered_map<char, int> re;
        for(auto e:t) re[e] ++; //{A:1, B:1, C:1}
        int cnt = 0, min_l = 0, minLen = INT_MAX;
        for(int i=0, j=0; j < s.length();j ++) {
            if(re.count(s[j])) {
                ++win[s[j]];
                if(re[s[j]] == win[s[j]]) cnt += 1;
            }
            
            while(cnt == re.size()) {
                if(j-i < minLen) {
                    min_l = i;
                    minLen = j-i+1;
                }
                if(re.count(s[i])) {
                    --win[s[i]];
                    if (re[s[i]] > win[s[i]]) {
                        --cnt;
                    }
                }
                ++i;
            }
           
        }
        return minLen > s.size()? "": s.substr(min_l, minLen);
    }
};

int main() {

    cout << Solution().minWindow("ADOBECODEBANC", "ABC") << endl; 
    // BANC

    cout << Solution().minWindow("a", "aa") << endl;
    // empty

    cout << Solution().minWindow("aa", "aa") << endl;
    // aa

    cout << Solution().minWindow("bba", "ab") << endl;
    // ba
    system( "PAUSE ");
    return 0;
}
