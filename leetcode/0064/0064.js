/**
 * WARNING 递归解法超时
 * @param {number[][]} grid
 * @return {number}
 */
function getSum(arr, dp, i, j) {
  if(i == 0 || j == 0) {
    return dp[i][j]
  } else  {
    return arr[i][j] + Math.min(getSum(arr, dp, i-1, j), getSum(arr, dp, i, j-1))
  }
}

var minPathSum = function(arr) {
  const row = arr.length
  const col = arr[0].length
  const dp = new Array(row).fill(0).map(() => new Array(col).fill(0))
  arr[0].forEach((e, i) => {
    if(i >= 1) {
      dp[0][i] = dp[0][i-1] + e
    } else {
      dp[0][i] = e
    }
  })
  arr.forEach((e, i) => {
    if(i >= 1) {
      dp[i][0] = dp[i-1][0] + e[0]
    } else {
      dp[i][0] = e[0]
    }
  })
  const sum = getSum(arr, dp, row - 1, col - 1);
  return sum
}