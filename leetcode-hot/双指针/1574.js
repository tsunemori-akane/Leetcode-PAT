/**
 * 思路：
 * 右指针 先找出 右边递增序列
 * 左指针依次便历，期间
 * 若arr[j] < arr[i] 不符题意 则j++；
 * 同时需要满足a[i+1] > arr[i];
 */

const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
})

const iter = rl[Symbol.asyncIterator]();

const readline = async () => (await iter.next()).value;

void async function findLengthOfShortestSubarray() {
  const arr = (await readline()).split(" ").map(e => parseInt(e));
  console.log(arr)
  const len = arr.length
    let i = 0, j = len - 1;
    while(j - 1 >= 0 && arr[j - 1] <= arr[j]) {
        j--;
    }
    if(j == 0) return 0
    let res = j;
    for(let i = 0; i < len; i++) {
        while(j < len && arr[j] < arr[i]) {
            j++;
        }
        res = Math.min(j - i - 1, res);
        if(i + 1 < len && arr[i] > arr[i+1]) {
        break;
        }
    }

    return res;
}()
  
