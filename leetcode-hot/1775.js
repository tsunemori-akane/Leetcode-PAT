/**
 * 给两个长度可能不等的整数数组num1 和 num2。两个数组所有值在1到6之间
 * 每次操作，你可以选择任意数组任意一个整数， 将它变成1-6之间任意值
 * 返回时nums1和nums2 所有数的和相等的最少操作次数
 * 
 * 思路：先求出两个数组最大变化和最小变化数组
 * 类似 [1,2,3,4,5] -> [5,4,3,2,1]
 * [1,2,3,4,5] -> [0,1,2,3,4]
 * 题目可以类似转换为 ：
 * 在一个数组中找出n个数使其和等于target（target即为两数组和之差的绝对值）
 * 该题有个小变化，n个数之和大于等于target即可， n尽可能的小
 */

function getSum(nums) {
  let sum = 0;
  for(const e of nums) {
    sum += e;
  }
  return sum
}


function getMinusDiff(nums) {
  let arr = []
  for(const e of nums) {
    arr.push(e - 1);
  }
  return arr
}
function getPlusDiff(nums) {
  let arr = []
  for(const e of nums) {
    arr.push(6 - e);
  }
  return arr
}
// function findMinStep(nums, target) {
//   const dp = new Array(target + 1).fill(Infinity)
//   dp[0] = 0; //和为0
//   for(const e of nums) {
//     for(let i = target; i >= e; i--) {
//       dp[i] = Math.min(dp[i], dp[i - e] + 1)
//     }
//   }
//   return dp[target] === Infinity ? -1 : dp[target]
// }
function findMinStep(nums, target) {
  let i = 0
  while(target > 0 && i < nums.length) {
    target -= nums[i];
    i++;
  }
  if(target > 0) return -1;
  return i;
}
var minOperations = function(nums1, nums2) {
  const sum1 = getSum(nums1);
  const sum2 = getSum(nums2);
  let minusDiff = []
  let plusDiff = []
  if(sum1 > sum2) {
    minusDiff = getMinusDiff(nums1)
    plusDiff = getPlusDiff(nums2)
  }
  else if(sum1 < sum2) {
    minusDiff = getMinusDiff(nums2)
    plusDiff = getPlusDiff(nums1) 
  } else {
    return 0
  }
  diffsArray = minusDiff.concat(plusDiff).sort((a, b) => b - a);
  let diff = Math.abs(sum1 - sum2);
  return findMinStep(diffsArray, diff)
}

console.log(minOperations([5,6,4,3,1,2],[6,3,3,1,4,5,3,4,1,3,4]));
// console.log(minOperations([6,6], [1]));
// console.log(minOperations([1,1,1,1,1,1,1], [6]));
