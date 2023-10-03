/**
 * N 棵胡杨 1 - N 排成一排
 * 一个月后 有 M 棵胡杨未能成活
 *  现补种胡杨 K 棵 如何补种 能得到 最多的连续胡杨
 * 输入描述
 * N 种植数量
 * M 未成活胡杨数量  
 * M 个空格分割的数， 按编号排列
 * K 最多补种的数量 0 <= K <= M
 * 输出最终最多连续胡杨个数
 * 
 * 模型： 假设活树为1 死树为0
 * 问题可以转换为
 * 求包含k个0的最长子序列
 */

const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
})

const iter = rl[Symbol.asyncIterator]()

const readline = async () => (await iter.next()).value

/**
 * 
 * @param {number} n 
 * @param {Array} arr 
 * @param {number} k 
 */
function helper(n, arr, k) {
  let left = 0, right = 0
  let ans = 0
  for(let left = 0, right = 0; right < n; i++) {
    
  }
}

void async function() {

}
