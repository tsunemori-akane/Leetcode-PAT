/**
 * 字符串解码
 * 输入 3[a2[c]]
 * 输出 accaccacc
 */

const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const iter = rl[Symbol.asyncIterator]();

const readline = async () => (await iter.next()).value;

/**
 * @param {string} s
 * @return {string}
 */
var decodeString = function(str) {
  const len = str.length
    let ans = ""
    for(let i = 0; i < len; i++) {
      if(str[i] >= 'a' && str[i] <= 'z') {
        ans += str[i]
      } else {
        let cnt = 0
        while(str[i] >= '0' && str[i] <= '9') {
          cnt = cnt * 10 + (str[i] - '0')
          i++
        }
        let pos = i  // pos 一定是 '['
        // 接着找出对应 ']'
        let lcnt = 1
        while(lcnt) {
          i++;
          if(str[i] == '[') lcnt ++;
          else if(str[i] == ']') lcnt --;
        }
        let temp = decodeString(str.substring(pos+1, i));
        while(cnt --) {
          ans += temp;
        }
      }
    }
    return ans;
  };

void (async function () {
  const str = await readline();
  console.log(str);
  console.log(decodeString(str));
  rl.close()
})();
