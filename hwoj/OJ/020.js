/** 
 * 给定两个字符串s1 s2
 * 对s1进行排列组合只要有一个为s2的子串则默认s1是s2的关联子串
 * 输出子串在s2起始位置，若不是则返回-1
 * abc
 * abbcaab
 * 输出 2
 */

const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
})

let iter = rl[Symbol.asyncIterator]();

const readline = async () => (await iter.next()).value;

void async function() {
  const s1 = await readline();
  const len1 = s1.length;
  const s2 = await readline();
  const len2 = s2.length;
  if(len1 > len2) return -1;
  const cntMap = {};
  let distinctCnt = 0
  for(const e of s1) {
    if(cntMap[e]) {
      cntMap[e] += 1;
    } else {
      cntMap[e] = 1;
      distinctCnt += 1;
    }
  }
  console.log(cntMap);
  let left = 0, right = 0, res = -1;
  
  while(right < len2) {
    const rChar = s2[right];
    
    while(right - left + 1 > len1) {
      if( cntMap[s2[left]] !== undefined ) {
        cntMap[s2[left]] += 1;
        distinctCnt += 1;
      }
      left ++;
      if( cntMap[s2[left]] && cntMap[s2[left]] > 0 ) {
        cntMap[s2[left]] -= 1;
        distinctCnt -= 1;
      }
    }

    if(cntMap[rChar] && cntMap[rChar] > 0) {
      cntMap[rChar] -= 1;
      if(cntMap[rChar] === 0) {
        distinctCnt -= 1;
      }
    }

    if(distinctCnt === 0 && right - left + 1 === len1) {
      res = left;
      break;
    }
    right ++;
  }
  console.log("left:", res)
  rl.close();
}();