class Solution {
public:
    bool isValid(string s) {
      unordered_map<char,int> m{{'(',1},{'{',2},{'[',3},{')',4},{'}',5},{']',6}};
      stack<char> st;
      //int count=0;
      //bool istrue=true;
      for (char c:s)
      { 
          int flag=m[c];
          if(flag>=1&&flag<=3) st.push(c);
          else if (!st.empty()&&m[st.top()]==flag-3) st.pop();
          else return 0;
          
      }
      if (!st.empty()) return 0;
      return 1;
    }
};

