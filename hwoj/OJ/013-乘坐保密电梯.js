/** 乘坐保密电梯
 * 给定一个数字序列， 每次根据序列中的数字n上升n或者下降n
 * 前后两次操作的方向必须相反，规定首次方向向上，自行组织序列顺序到达指定楼层或小于该楼层最近的序列组合
 * 输入描述
 * 第一行 5 3 （期望楼层，取值范围[1, 50]; 序列总数，取值范围[1, 23]）
 * 第二行 1 2 6 序列 每个值的取值范围[1, 50]
 * 输出描述：能够到达的楼层或者小于该楼层的最近序列
 * 6 2 1
 * 说明 操作电梯不限定楼梯范围，必须对序列每一个项进行操作
 */
const readLine = require("readline");
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout,
});
const arr = [];

rl.on("line", function (line) {
  arr.push(line);
  if(arr.length === 2) {
    rl.close();
  }
})

rl.on("close", function(){
  const f = Number(arr[0].substring(0,1));
  console.log("f", f);
  const floors = arr[1].split(" ").map(e => Number(e));
  console.log("floors", floors);

})