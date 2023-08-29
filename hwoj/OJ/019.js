/**
 * 给定两个等长字符串A，B和正整数V. 求满足以下两个条件的最大连续子串长度
 * 1. 连续子串在A、B中位置相同
 * 2. 该子串任意A[i]-B[i]的绝对值之和 <= V (ascii码相减)
 * xxcdefg
 * cdefghi
 * 5
 * 输出 2 
 * 双指针解法
 */

const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

let iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

void async function() {
  const str1 = await readline();
  const str2 = await readline();
  const V = Number(await readline());
  const arr = [];
  let sum = 0;
  let temp = 0;
  let max = 0;
  for(let i = 0; i < str1.length; i++) {
    const abs = Math.abs(str1.charCodeAt(i) - str2.charCodeAt(i))
    arr.push(abs);
  }
  console.log(arr)
  for(let i = 0, j = 0; j < arr.length;) {
    if(sum + arr[j] <= V) {
      sum += arr[i];
      j++;
      temp += 1;
      
    } else if(i < j){
      sum -= arr[i];
      i++;
      temp -= 1;
    } else if(i == j) {
      i++;
      j++;
    }
    max = Math.max(temp, max);
  }
  console.log(max)
  rl.close();
}()