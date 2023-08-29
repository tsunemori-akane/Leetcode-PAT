/**
 * 工厂有m条流水线， 并行完成n个独立作业
 * 每个独立作业处理时间分别为 t1 t2 t3...tn
 * 当n>m 首先处理时间短的m个作业进入流水线，其它的等待，
 * 当某个作业完成，从剩余作业取出处理时间最短的进行处理
 * 第一行输入 m n
 * 第二行输入n个整数，表示作业处理时长
 * 输出处理完作业总时长
 */

const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
})

let iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

void async function() {
  let [m, n] = (await readline()).split(" ").map(e => Number(e))
  // const str1 = await readline()
  // let [m, n] = str1.split(" ").map(e => Number(e))
  // const str2 = await readline()
  // let arr = str2.split(" ").map(e => Number(e))
  let arr = (await readline()).split(" ").map(e => Number(e))
  arr.sort((a,b) => a - b)
  
  if(n <= m) {
    console.log(arr[arr.length-1])
  } else {
    console.log(arr, m ,n)
    const result = new Array(m).fill(0)
    let pointer = 0
    while(pointer < n-1) {
      for(let i = 0; i < m && pointer + i < n; i++) {
        result[i] += arr[pointer+i];
      }
      pointer += m;
    }
    result.sort((a,b) => a - b)
    console.log(result)
    console.log(result[m-1]);
    
  }
  rl.close();
}()