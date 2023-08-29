/** 
 * k数之和
 * 给定整数数组nums、数字k、整数目标值target
 * 问nums中是否存在k个元素使得其相加结果为target
 * 输出所有符合条件且不重复的k个元素 个数 (2 <= k <= 100)
 * Given an integer array nums, a number k, and a target value. The question is whether there 
 * exist k elements in nums that add up to the target.If so, determine how many sets of k numbers 
 * satisfy this condision
 * 例子 输入 
 * -1 0 1 2 -1 -4
 * 3
 * 0
 * 输出
 * 2 （-1 0 1）（-1 -1 2）
 * 
 * 状态转移方程 f(n, k, target) = f(n - 1, k, target) + f(n - 1, k - 1, target - num[n])
 * 解释：分两种情况，取第n个数 和 不取第n个数
 */
const readLine = require("readline");
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let cnt = 0
let arr = [-1, 0, 1, 2, -1, -4]
let k = 3
let target = 0
let results = [];

rl.on("line", function (line) {
  cnt += 1;
  if(cnt === 1) {
    arr = line.split(" ").map(e => Number(e))
  }
  if(cnt === 2) {
    k = Number(line)
  }
  if(cnt === 3) {
    target = Number(line)
    rl.close()
  }
})



/**
 * 
 * @param {any[]} arr 
 * @param {number} target 
 * @param {number} k 
 * @param {number} res 
 * @returns {number}
 */
function ksum(arr, target, k, res) {
  const len = arr.length
  if(len < k) {
    return 0;
  }
  if(k == 2) {
    const seen = new Map();
    for(let i=0; i<len; i++) {
      const remain = target - arr[i]
      if(seen.has(remain)) {
        res += 1;
        while( i + 1 < len && arr[i + 1] === arr[i]) {
          i++
        }
      }
      seen.set(arr[i], i)
    }
    return res
  } else {
    
    return ksum(arr.slice(0, len-1), target, k, res) + ksum(arr.slice(0, len-1), target-arr[len-1],k-1, res)
  }
}

rl.on("close", function() {
  arr.sort((a,b) => a - b);
  console.log(target, k, arr)
  console.log(ksum(arr, target, k, 0))
})


/**
 * 
 * @param {*} nums 
 * @param {*} k 
 * @param {*} target 
 * @returns 
 * by chatGPT
 */
function findKSum(nums, k, target) {
  const results = [];
  const n = nums.length;

  // 辅助函数，返回 k 个数的和为 target 的组合
  function kSumHelper(start, k, target, currentResult) {
    if (k === 2) {
      const seen = new Map();
      for (let i = start; i < n; i++) {
        const complement = target - nums[i];
        if (seen.has(complement)) {
          results.push([...currentResult, complement, nums[i]]);
          while (i + 1 < n && nums[i + 1] === nums[i]) {
            i++;
          }
        }
        seen.set(nums[i], i);
      }
    } else {
      // 该target情况下的所有组合 即为nums[i]固定会取的情况 之和
      for (let i = start; i < n - k + 1; i++) {
        if (i > start && nums[i] === nums[i - 1]) {
          continue;
        }
        kSumHelper(i + 1, k - 1, target - nums[i], [...currentResult, nums[i]]);
      }
    }
  }

  nums.sort((a, b) => a - b); // 排序数组
  kSumHelper(0, k, target, []);

  return results;
}