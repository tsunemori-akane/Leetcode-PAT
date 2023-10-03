/** 
 * 给出n种硬币，每种硬币数量不限
 * 给出目标值target
 * 求出得到目标值所需最少硬币数量
 */

var coinChange = function (coins, amount) {
  const n = amount;
  const dp = new Array(n + 1).fill(Infinity);
  dp[0] = 0
  for(const x of coins) {
    for(let j = x; j <= n; ++j) {
      dp[j] = Math.min(dp[j], dp[j - x] + 1)
    }
  }
  return dp[n] > n ? -1 : dp[n];
}