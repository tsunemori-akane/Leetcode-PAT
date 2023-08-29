/**
 * 阿里巴巴找黄金宝箱3
 * 有 编号 0-N个箱子，每个箱子上面贴有一个数字
 * 阿里巴巴念出一个数字，查看宝箱中存在两个箱子贴的数字相同且编号之差绝对值小于等于念出的数字
 * 存在返回最先找到的那对宝箱左边的箱子编号，没有返回-1
 */

const readLine = require("readline");
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let cnt = 0
let spell
let arr = []

rl.on("line", function (line) {
  cnt += 1;
  if(cnt === 1) {
    arr = line.split(" ").map(e => Number(e))
  }
  if(cnt === 2) {
    spell = Number(line)
    rl.close()
  }
})

rl.on("close", function(){
  console.log(spell, arr)
  let set = new Set(); // 记录前面出现过的数字
  let map = {}; // Record<n, index>
  let res = -1;
  for(let i = 0; i < arr.length; i++) {
    if(set.has(arr[i])) {
      if(Math.abs(i - map[arr[i]]) <= spell) {
        res = map[arr[i]]
        break
      }
    } else {
      set.add(arr[i])
      map[arr[i]] = i
    }
  }
  if(res == -1) {
    console.log(res)
  } else {
    console.log(res + 1);
  }
})