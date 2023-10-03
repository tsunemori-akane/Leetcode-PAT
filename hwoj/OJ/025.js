/**
 * 一堆雨花石（数量n 重量各异） 送给两人 要求重量相等 雨花石送完
 * 第一行输入 雨花石个数 n
 * 第二行输入 各个雨花石数量
 * 输出 ： 可均分，从当前雨花石最少拿出几块， 使两堆重量相等，否则输出-1
 * 状态转移方程
 * dp[i][j] = min(dp[i-1][j] ,dp[i-1][j-w])
 */

const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
})

const iter = rl[Symbol.asyncIterator]()

const readline = async () => (await iter.next()).value

/**
 * 
 * @param {number} n 
 * @param {array} w 
 * @returns boolean 
 */
function helper(n, w) {
  const sum = w.reduce((a,b) => a+b);
  if(sum % 2 !== 0) return false
  const bag = sum / 2
  // 初始化dp
  const dp = new Array(n+1).fill(0).map(() => new Array(bag+1).fill(0))
  // 初始化第一行
  for(let i = 1; i <= n; i++) {
    dp[0][i] = n;
  }
  dp[0][0] = 0
  for(let i = 0; i <= n; i ++) {
    const num = w[i-1];
    for(let j = 1; j <= bag; j++) {
      if(j < num) {
        dp[i][j] = dp[i-1][j]
      } else {
        dp[i][j] = Math.min(dp[i-1][j], dp[i-1][j-num] + 1)
      }
    }
  }

  if(dp[n][bag] == n) {
    return -1
  } else {
    return Math.min(n - dp[n][bag], dp[n][bag])
  }
}

void async function () {
  const n = parseInt((await readline()));
  const weights = (await readline()).split(" ").map(e => parseInt(e))
  helper(n, weights)
}